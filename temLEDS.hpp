// ==========================================================================
//
// File      : temLEDS.hpp
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

#ifndef TEMLEDS_HPP
#define TEMLEDS_HPP

#include "hwlib.hpp"
#include "temperature.hpp"
#include "LEDstrip.hpp"

/// \brief
/// This class defines combination of the DHT11 sensor and the WS2801 LEDS
/// \details
/// This class needs a set up temperature class and a set up LEDstrip class. It combines their functions to achieve a temperature based LED strip.
class temLEDS{
private:
	temperature sensor;
	LEDstrip LEDS;
public:
	temLEDS(temperature sensor, LEDstrip LEDS):
	sensor(sensor),
	LEDS(LEDS)
	{}

/// \brief
/// This function merges the temperature readings with the LEDS
/// \details
/// First the temperature will be asked, all data including the checksum will be printed to the console, allowing checks
/// The colors will be initialised based on the temperature.
/// The colors are made brighter in intervals to ensure a semi well transition
/// The colors, from low temperatures to high are: green, blue, mint, orange, red
/// If the temperature is exceptionally high or low, disco function will be started to show temperature readings were incorrect
	void init();
};

#endif // TEMLEDS_HPP