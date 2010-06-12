/*
 *  MidiExceptions.h
 *  glitches
 *
 *  Created by hec on 5/20/10.
 *  Copyright 2010 aer studio. All rights reserved.
 *
 */



#pragma once

#include "cinder/Exception.h"

namespace cinder { namespace midi {

class MidiExc : public Exception {
	
};

class MidiExcNoPortsAvailable : public MidiExc {

};

class MidiExcPortNotAvailable : public MidiExc {

};
	
} // namespace midi
} // namespace cinder
