/*
 *  MidiMessage.h
 *  glitches
 *
 *  Created by hec on 5/20/10.
 *  Copyright 2010 aer studio. All rights reserved.
 *
 */

#pragma once




namespace cinder { namespace midi {
	
	class Message {
	public:
		
		Message();
		
		int port;
		int channel;
		int status;
		int byteOne;
		int byteTwo;
		double timeStamp;
		
		Message& copy(const Message& other);
	};

} // namespace midi
} // namespace cinder