// ==========================================================================
//
// File      : main.cpp
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

#include "hwlib.hpp"
#include "LEDstrip.hpp"
#include "temperature.hpp"
#include "temLEDS.hpp"

/// \brief 
/// This main file/function only does the setup
/// \details
/// The function does the following things
/// - Set up the pins
/// - Set up the LED strip, the temperature class and the intialisor
/// - In a while loop, request new data every 5 seconds and update the LEDS
int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(1000);

	auto cl = hwlib::target::pin_out(hwlib::target::pins::d22);
	auto data = hwlib::target::pin_out(hwlib::target::pins::d25);
	auto temp = hwlib::target::pin_oc(hwlib::target::pins::d24);

	LEDstrip strip = {cl, data,16};
	temperature a = temperature(temp);
	temLEDS test = temLEDS(a, strip);
	
	while(1){
		a.request();
		test.init();
		hwlib::wait_ms(5000);
	}
}