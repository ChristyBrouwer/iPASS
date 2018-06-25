// ==========================================================================
//
// File      : LEDstrip.cpp
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
#include "LEdstrip.hpp"

/// Uses bitshifting
void LEDstrip::color(int red, int green, int blue){
	clock.set(0);
	hwlib::wait_us(500);
	
	for(int j = 0; j < numLEDS; j++){
		int r = red;
		int g = green;
		int b = blue;
		for(int i= 0; i < 8; i++){
			data.set((r & 0b10000000) == 0b10000000);
			clock.set(1);
			hwlib::wait_us(2);
			clock.set(0);
			r = r<<1;
		}
		for(int i= 0; i < 8; i++){
			data.set((b & 0b10000000) == 0b10000000);
			clock.set(1);
			hwlib::wait_us(2);
			clock.set(0);
			b = b<<1;
		}
		for(int i= 0; i < 8; i++){
			data.set((g & 0b10000000) == 0b10000000);
			clock.set(1);
			hwlib::wait_us(2);
			clock.set(0);
			g = g<<1;
		}
	}
	clock.set(0);
	hwlib::wait_us(500);
}


void LEDstrip::disco(){
	while(1){
		for(int i = 0 ; i < 10; i++){
			color(83,0,0);
			hwlib::wait_ms(100);
			color(0,0,51);
			hwlib::wait_ms(100);
			color(83,51,0);
			hwlib::wait_ms(100);
			color(0,255,51);
			hwlib::wait_ms(100);
			color(0,127,0);
			hwlib::wait_ms(100);
			color(83,0,51);
			hwlib::wait_ms(100);
		}
	}
}

void LEDstrip::off(){
	color(0,0,0);
}