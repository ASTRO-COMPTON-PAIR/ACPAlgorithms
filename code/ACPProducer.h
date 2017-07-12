/***************************************************************************
 ACPProducer.h
 -------------------
 copyright            : (C) 2014-2017 Andrea Bulgarelli
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

#ifndef _ACPPRODUCER_H
#define _ACPPRODUCER_H

#include "ACPBuffer.h"

namespace ACPAlgorithm {
	
	
	///ACP algorithm base class
	class ACPProducer {
		
	protected:
		
		ACPBuffer* buffer_output;
		
	public:
		
		ACPProducer(ACPBuffer* buffer_output);
		
		void setBufferOutput(ACPBuffer* buffer_output);
		
		ACPBuffer* getBufferOutput();
		
	};
	
}

#endif
