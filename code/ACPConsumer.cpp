/***************************************************************************
 ACPConsumer.cpp
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

#include "ACPConsumer.h"
#include <iostream>

namespace ACPAlgorithm {

ACPConsumer::ACPConsumer(ACPBuffer* buffer_input) {
	this->buffer_input = buffer_input;
}

void ACPConsumer::setBufferInput(ACPBuffer* buffer_input) {
	this->buffer_input = buffer_input;
}

ACPBuffer* ACPConsumer::getBufferInput() {
	return buffer_input;
}


//---------

ACPBufferCleaner::ACPBufferCleaner(ACPBuffer* buffer_input) : ACPConsumer(buffer_input) {

}

void *ACPBufferCleaner::run() {
	
	std::cout << "Thread cleaner started" << std::endl;
	
	
	while (true) {
		ACPData* d = buffer_input->get();
		//cout << "del" << endl;
		delete d;
	}
	return 0;
	
}

}
