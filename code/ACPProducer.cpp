/***************************************************************************
 ACPProducer.cpp
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

#include "ACPProducer.h"

namespace ACPAlgorithm {

ACPProducer::ACPProducer(ACPBuffer* buffer_output) {
	this->buffer_output = buffer_output;
}

void ACPProducer::setBufferOutput(ACPBuffer* buffer_output) {
	this->buffer_output = buffer_output;
}

ACPBuffer* ACPProducer::getBufferOutput() {
	return this->buffer_output;
}

}
