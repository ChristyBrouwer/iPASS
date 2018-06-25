// ==========================================================================
//
// File      : temLEDS.cpp
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
#include "temLEDS.hpp"

void temLEDS::init(){
	int temp = sensor.temp();
	/// I chose for disco function if it's under 0 zero degrees, this because of aesthetic reasons (christmas tree)
	if(temp > 0 and temp < 10){
		LEDS.color(0, 8, 0);
		hwlib::wait_us(10);
		LEDS.color(0, 40, 0);
		hwlib::wait_us(10);
		LEDS.color(0, 80, 0);
		hwlib::wait_us(10);
		LEDS.color(0, 150, 0);
		hwlib::wait_us(10);
		LEDS.color(0, 170, 0);
		hwlib::wait_us(10);
		LEDS.color(0, 200, 0);
		hwlib::wait_us(10);
		LEDS.color(0, 255, 0);
		hwlib::wait_us(10);
	}
	else if(temp >=10 and temp <17){
		LEDS.color(0, 0, 8);
		hwlib::wait_us(10);
		LEDS.color(0, 0, 40);
		hwlib::wait_us(10);
		LEDS.color(0, 0, 80);
		hwlib::wait_us(10);
		LEDS.color(0, 0, 150);
		hwlib::wait_us(10);
		LEDS.color(0, 0, 170);
		hwlib::wait_us(10);
		LEDS.color(0, 0, 200);
		hwlib::wait_us(10);
		LEDS.color(0, 0, 255);
	}
	else if(temp >=17 and temp <20){
		LEDS.color(0, 8, 8);
		hwlib::wait_us(10);
		LEDS.color(0, 40, 40);
		hwlib::wait_us(10);
		LEDS.color(0, 80, 80);
		hwlib::wait_us(10);
		LEDS.color(0, 150, 150);
		hwlib::wait_us(10);
		LEDS.color(0, 170, 170);
		hwlib::wait_us(10);
		LEDS.color(0, 200, 200);
		hwlib::wait_us(10);
		LEDS.color(0, 255, 255);
	}
	else if (temp >=20 and temp <25){
		LEDS.color(8, 8, 0);
		hwlib::wait_us(10);
		LEDS.color(40, 40, 0);
		hwlib::wait_us(10);
		LEDS.color(80, 80, 0);
		hwlib::wait_us(10);
		LEDS.color(150, 130, 0);
		hwlib::wait_us(10);
		LEDS.color(170, 130, 0);
		hwlib::wait_us(10);
		LEDS.color(200, 130, 0);
		hwlib::wait_us(10);
		LEDS.color(255, 130, 0);
	}
	else if (temp >=25){
		LEDS.color(8, 0, 0);
		hwlib::wait_us(10);
		LEDS.color(40, 0, 0);
		hwlib::wait_us(10);
		LEDS.color(80, 0, 0);
		hwlib::wait_us(10);
		LEDS.color(150, 0, 0);
		hwlib::wait_us(10);
		LEDS.color(170, 0, 0);
		hwlib::wait_us(10);
		LEDS.color(200, 0, 0);
		hwlib::wait_us(10);
		LEDS.color(255, 0, 0);
	}
	///If the reading isn't conclusive disco function will be requested
	else{
		LEDS.disco();
	}
};