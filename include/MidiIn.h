/*
 *  MidiIn.h
 *  glitches
 *
 *  Created by hec on 5/20/10.
 *  Copyright 2010 aer studio. All rights reserved.
 *
 */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>

#include "RtMidi.h"

#include "MidiExceptions.h"
#include "MidiMessage.h"
#include "MidiConstants.h"

//#include <boost/signal.hpp>


namespace cinder { namespace midi {

void MidiInCallback( double deltatime, std::vector< unsigned char > *message, void *userData );

class Input {
public:
	Input();
	virtual ~Input();
	
	void listPorts();
	unsigned int getNumPorts()const{ return mNumPorts; }
	void openPort(unsigned int port = 0);
	void closePort();
	void processMessage(double deltatime, std::vector<unsigned char> *message);
	unsigned int getPort()const;
	
	bool hasWaitingMessages();
	bool getNextMessage(Message*);
	
	std::vector<std::string> mPortNames;
	
	//typedef boost::signal<void (Message*)> signal_t;
		
	//signal_t mSignal;
	
protected:
	
	RtMidiIn mMidiIn;
	unsigned int mNumPorts;
	unsigned int mPort;
	
		
	std::deque<Message*> mMessages;
	
};

} // namespace midi
} // namespace cinder