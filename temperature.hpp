// ==========================================================================
//
// File      : temperature.hpp
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

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#include "hwlib.hpp"

class temperature{
private:
	hwlib::target::pin_oc & pin;
public:
	temperature(hwlib::target::pin_oc & pin):
	pin(pin)
	{}

/// \brief
/// getByte returns the 1 byte int it gets from the dht11 sensor
/// \details
/// The function returns one int of 8 bits. The dht11 sensor has to be requested first.
/// After the sensor has had a request this function has to be called immediately to not miss bytes
/// It waits for all 8 bits and uses bitshifting to end up with the right integer.
	int getByte();

/// \brief
/// Request data from the dht11 sensor
/// \details
/// The function requests a data transfer. It then waits till the sensor sent an approval back.
/// This function needs to be called before the getByte function. The latter needs to be called right after request()
	void request();

/// \brief
/// Prints the data it receives from the dht11 sensor
/// \details
/// Uses the getByte function to receive all the bytes
/// Then prints these
	void print();

/// \brief
/// Returns only the temperature in Celsius, without decimals.
/// \details
/// Cycles through all the bytes and prints these in order to be able to check them
/// Only returns the full temperature, decimals aren't included
/// This causes the temperature to have a possibility of being off by one degree
	int temp();
};

#endif // TEMPERATURE_HPP