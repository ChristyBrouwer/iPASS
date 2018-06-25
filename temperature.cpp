// ==========================================================================
//
// File      : temperature.cpp
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
#include "temperature.hpp"

/// Uses bitshifting
int temperature::getByte(){
	int result;
	for(int i= 0; i<7; i++){
		hwlib::wait_us(50);
		if(pin.get() == 0){
			result = result<<1;
		}
		else{
			result += 1;
			result = result<<1;
			while(pin.get() == 1){};
		}
		while(pin.get() == 0){};
	}
	hwlib::wait_us(50);
	if(pin.get() == 1){
		result += 1;
		while(pin.get() == 1){};
	}
	while(pin.get() == 0){};
	return result;
};

void temperature::request(){
	pin.set(0);
	hwlib::wait_ms(20);
	pin.set(1);
	hwlib::wait_us(40);
	
	while(pin.get() == 0){};
	while(pin.get() == 1){};
	while(pin.get() == 0){};
};

int temperature::temp(){
	int hum1 = getByte();
	int hum2 = getByte();
	int tem1 = getByte();
	int tem2 = getByte();
	int sum = getByte();
	hwlib::cout << "The humidity is: " << hum1 << "," << hum2 << hwlib::endl;
	hwlib::cout << "The temperature is: " << tem1 << "," << tem2 << hwlib::endl;
	hwlib::cout << "The checksum is: " << sum << hwlib::endl;
	return tem1;
};

void temperature::print(){
	int hum1 = getByte();
	int hum2 = getByte();
	int tem1 = getByte();
	int tem2 = getByte();
	int sum = getByte();
	hwlib::cout << "The humidity is: " << hum1 << "," << hum2 << hwlib::endl;
	hwlib::cout << "The temperature is: " << tem1 << "," << tem2 << hwlib::endl;
	hwlib::cout << "The checksum is: " << sum << hwlib::endl;
};
