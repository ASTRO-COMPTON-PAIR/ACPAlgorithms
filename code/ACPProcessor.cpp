/***************************************************************************
 ACPProcessor.cpp
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

#include "ACPProcessor.h"

namespace ACPAlgorithm {

void ACPProcessorThread::init(ACPProcessor* alg) {
	this->alg = alg;
	this->stopb = false;
}

void *ACPProcessorThread::run() {
	while(!stopb) {
		alg->processBufferElement();
	}
	return 0;
}

void ACPProcessorThread::stop() {
	stopb = true;
}


ACPProcessor::ACPProcessor(ACPTelescopeConfig* telConfig, ACPBuffer* buffer_input, ACPBuffer* buffer_output) : ACPConsumer(buffer_input), ACPProducer(buffer_output) {
	this->config = telConfig;
}

void ACPProcessor::processBufferElement() {
	ACPData* input = buffer_input->get();
	ACPData* output = process(input);
	if(buffer_output)
		buffer_output->put(output);
}

}
