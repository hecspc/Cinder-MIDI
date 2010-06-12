/*
 *  MidiConstants.h
 *  glitches
 *
 *  Created by hec on 5/20/10.
 *  Copyright 2010 aer studio. All rights reserved.
 *
 */

#pragma once

#include "cinder/Cinder.h"

#ifdef CINDER_LINUX
	#define __LINUX_ALSASEQ__
#elif defined(CINDER_MSW)
	#define __WINDOWS_MM__
#elif defined(CINDER_MAC)
	#define __MACOSX_CORE__
#endif


// channel info
#define    MIDI_NOTE_OFF             128
#define    MIDI_NOTE_ON              144
#define    MIDI_POLY_PRESSURE        160
#define    MIDI_CONTROL_CHANGE       176
#define    MIDI_PROGRAM_CHANGE       192
#define    MIDI_CHANNEL_PRESSURE     208
#define    MIDI_PITCH_BEND           224

// system exclusive
#define    MIDI_NOTE_ON              144

// system common
#define    MIDI_TIME_CODE            241
#define    MIDI_SONG_POS_POINTER     242
#define    MIDI_SONG_SELECT          243
#define    MIDI_TUNE_REQUEST         244
#define    MIDI_EOX                  247

// system realtime
#define    MIDI_TIME_CLOCK           248
#define    MIDI_START                250
#define    MIDI_CONTINUE             251
#define    MIDI_STOP                 252
#define    MIDI_ACTIVE_SENSING       254
#define    MIDI_SYSTEM_RESET         255