/***************************************************************************
 ACPConsumer.h
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

#ifndef _ACPCONSUMER_H
#define _ACPCONSUMER_H

#include "ACPBuffer.h"
#include <acputils/Thread.h>

namespace ACPAlgorithm {
	
	
	///ACP algorithm base class
	class ACPConsumer {
		
	protected:
		
		ACPBuffer* buffer_input;
		
	public:
		
		ACPConsumer(ACPBuffer* buffer_input);
		
		void setBufferInput(ACPBuffer* buffer_input);
		
		ACPBuffer* getBufferInput();
		
	};
	
	
	class ACPBufferCleaner : public ACPConsumer, public ACPUtils::Thread {
	
	public:
		
		ACPBufferCleaner(ACPBuffer* buffer_input);
		
		void *run();
	};
	
}

#endif
