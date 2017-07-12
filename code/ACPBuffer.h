/***************************************************************************
 ACPBuffer.h
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

#ifndef _ACPBUFFER_H
#define _ACPBUFFER_H

#include <pthread.h>
#include <semaphore.h>
#include "ACPData.h"
#include <string>

//the producer/consumer (aka Bounded Buffer) problem.
namespace ACPAlgorithm {
	
	class ACPBuffer {
		
	private:
		
		ACPData** buffer;
		int fill;
		int use;
		int circularBuffer;
		sem_t* empty;
		sem_t* full;
		pthread_mutex_t mutex;
		std::string semname1;
		std::string semname2;

		std::string _name;
		
		int size;
		
	public:
		
		ACPBuffer(std::string name, int size);
		~ACPBuffer();
		///Put data into local buffer
		///The call is blocking if the buffer is full. Test it before with isFull()
		void put(ACPData* data);
		
		///get processed data from buffer
		///The call is blocking if the buffer is empty.
		ACPData* get();

		std::string getName() {
			return _name;
		}
		
		int getBufferSize();
		
		bool isFull();
		
		ACPData* getNextCircularBuffer();
	};
}

#endif
