/***************************************************************************
 ACPProcessor.h
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

#ifndef _ACPPROCESSOR_H
#define _ACPPROCESSOR_H

#include <acputils/Thread.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "ACPData.h"
#include "ACPBuffer.h"
#include "ACPProducer.h"
#include "ACPConsumer.h"
#include "ACPTelescopeConfig.h"

namespace ACPAlgorithm {
	

	///ACP algorithm base class
	class ACPProcessor : public ACPConsumer, public ACPProducer {
		
	protected:
		
		ACPTelescopeConfig* config;
		
		
	public:
		
		ACPProcessor(ACPTelescopeConfig* telConfig, ACPBuffer* buffer_input = 0, ACPBuffer* buffer_output = 0);
		
		virtual void init() = 0;
		
		virtual void processBufferElement();
		
		///write the algorithm in this method. Use this method also the test manually the algorithm
		virtual ACPData* process(ACPData* input) = 0;
		
	};
	
	class ACPProcessorThread : public ACPUtils::Thread {
	private:
		
		ACPProcessor* alg;
		
		bool stopb;
		
	public:
				
		void init(ACPProcessor* alg);
		
		void *run();
		
		void stop();
	};
}

#endif
