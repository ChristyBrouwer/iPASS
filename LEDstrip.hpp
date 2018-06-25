// ==========================================================================
//
// File      : LEDstrip.hpp
// Part of   : C++ library for temperature based leds
// Copyright : Christy Brouwer 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

// This file contains Doxygen lines
/// @file

#ifndef LEDSTRIP_HPP
#define LEDSTRIP_HPP

#include "hwlib.hpp"

class LEDstrip{
private:
	hwlib::target::pin_out clock;
	hwlib::target::pin_out data;
	int numLEDS;
public:
	LEDstrip(auto clock, auto data, int numLEDS):
	clock(clock),
	data(data),
	numLEDS(numLEDS)
	{}

/// \brief
/// Put row of leds to 1 color
/// \details
/// This function sends the given colorchannels to all the 
/// leds in the row. It needs the 3 colorchannels, red, green and blue. Every value needs an int between 0 and 255.
/// Brightness can be changed by sending a less strong signal to the color
/// f.e. instead of 255 red only send 160 for a softer red.
	void color(int red, int blue, int green);

/// \brief
/// Changes color row of leds every 100 ms
/// \details
/// This function doesn't need parameters. It
/// will change the led strip's color every 100 ms
/// it has it's own color initialisors for this.
/// Used as error signal
	void disco();

/// \brief
/// Turns off leds
/// \details
/// Turns the entire row of leds off by using the color function, turning every color off individually.
	void off();
};

#endif // LEDSTRIP_HPP