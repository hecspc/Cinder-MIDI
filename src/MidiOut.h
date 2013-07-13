/*
 *  MidiOut.h
 *
 *  Created by Andrea Cuius
 *  Nocte Studio Ltd. Copyright 2013 . All rights reserved.
 *
 *  www.nocte.co.uk
 *
 */

#pragma once

#include "RtMidi.h"

namespace cinder { namespace midi {

class Output {

public:
    
	Output()                { listPorts(); }
    
    ~Output()               { closePort(); }
	
	void closePort()        { mMidiOut.closePort(); }
    
	size_t getNumPorts()    { return mPortNames.size(); }
    
	void listPorts()
    {
        mPortNames.clear();
        
        int portsN = mMidiOut.getPortCount();
		
        std::cout << "MidiOut: " << portsN << " available." << std::endl;
		
        for (size_t i = 0; i < portsN; ++i)
        {
			std::cout << i << ": " << mMidiOut.getPortName(i).c_str() << std::endl;
			mPortNames.push_back( mMidiOut.getPortName(i) );
		}
	}
    
	
    void openPort( size_t port = 0 )
    {
        if ( getNumPorts() == 0 )
            throw MidiExcNoPortsAvailable();
            
        if ( port + 1 > getNumPorts() )
            throw MidiExcPortNotAvailable();
    
        mPort = port;
        mName = mMidiOut.getPortName(port);
        
        mMidiOut.openPort( mPort );
    }
    
    
    void sendMessage( size_t channel, size_t type, size_t val_a, size_t val_b )
    {
        std::vector<unsigned char> rtMsg;
        type = type | channel;
        rtMsg.push_back( type );
        rtMsg.push_back( val_a );
        rtMsg.push_back( val_b );
        mMidiOut.sendMessage( &rtMsg );
    }
    
	std::string getName()   { return mName; };
    
    std::vector<std::string> getPortNames() { return mPortNames; }

    
protected:
	
	RtMidiOut                   mMidiOut;
	uint32_t                    mPort;
    std::vector<std::string>    mPortNames;
	std::string                 mName;

};

} // namespace midi
} // namespace cinder


