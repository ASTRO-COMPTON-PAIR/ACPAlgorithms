/***************************************************************************
 ACPBuffer.cpp
 -------------------
 copyright            : (C) 2014-2017 Andrea Bulgarelli, Alessio Aboudan
 email                : bulgarelli@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "ACPBuffer.h"
#include <iostream>
#include <fcntl.h>

namespace ACPAlgorithm {

ACPBuffer::ACPBuffer(std::string name, int size) {
	this->buffer = (ACPData**) new ACPData* [size];
	this->size = size;
	fill = 0;
	use  = 0;
	circularBuffer = 0;
	_name = name;
	semname1 = "empty_";
	semname1 += name;
	sem_unlink(semname1.c_str());
	semname2 = "full_";
	semname2 += name;
	sem_unlink(semname2.c_str());
	//sem_init(&empty, 0, size); // MAX buffers are empty to begin with...
	//sem_init(&full, 0, 0);    // ... and 0 are full
	empty = sem_open(semname1.c_str(), O_CREAT, 0644, size);
	if (empty == SEM_FAILED) {
		perror(" empty sem_open() failed ");
		exit(0);
	}
	full = sem_open(semname2.c_str(), O_CREAT, 0644, 0);
	if (full == SEM_FAILED) {
		perror(" empty sem_open() failed ");
		exit(0);
	}
	pthread_mutex_init(&mutex, NULL);
}

ACPBuffer::~ACPBuffer() {
	sem_close(empty);
	sem_unlink(semname1.c_str());
	sem_close(full);
	sem_unlink(semname2.c_str());
}

void ACPBuffer::put(ACPData* data) {
	int ret = sem_wait(empty);
	if(ret != 0) {
		perror("empty sem_wait() failed ");
		exit(0);
	}
	// scope of lock reduced
	pthread_mutex_lock(&mutex);
	
	this->buffer[fill] = data;
	fill = (fill + 1) % size;
	
	pthread_mutex_unlock(&mutex);

	ret = sem_post(full);
	if(ret != 0) {
		perror("full sem_post() failed ");
		exit(0);
	}

}

bool ACPBuffer::isFull() {
	if(fill == size - 1)
		return true;

	return false;
}

ACPData* ACPBuffer::get() {
	int ret = sem_wait(full);
	if(ret != 0) {
		perror("full sem_wait() failed ");
		exit(0);
	}
	
	// scope of lock reduced
	pthread_mutex_lock(&mutex);
	
	ACPData* b = buffer[use];
	use = (use + 1) % size;
	
	pthread_mutex_unlock(&mutex);

	ret = sem_post(empty);
	if(ret != 0) {
		perror("empty sem_post() failed ");
		exit(0);
	}
	
	return b;
}

ACPData* ACPBuffer::getNextCircularBuffer() {
	
	ACPData* b = buffer[circularBuffer];
	circularBuffer = (circularBuffer + 1) % size;
	return b;
}


int ACPBuffer::getBufferSize() {
	return this->size;
}

}
