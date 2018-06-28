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

void temperature::print(){
	int hum1 = getByte();
	int hum2 = getByte();
	int temC = getByte();
	int tem2 = getByte();
	int sum = getByte();
	
	int temF = temC*1.8 + 32;
	int temG = temC/3;
	hwlib::cout << "The humidity is: " << hum1 << "," << hum2 << hwlib::endl;
	hwlib::cout << "The temperature in C is: " << temC << "," << tem2 << hwlib::endl;
	hwlib::cout << "The temperature in F is: " << temF << hwlib::endl;
	hwlib::cout << "The temperature on a scale of 1 to 10 is: " << temG << hwlib::endl;
	hwlib::cout << "The checksum is: " << sum << hwlib::endl;
};

int temperature::tempC(){
	getByte();
	getByte();
	int tem1 = getByte();
	int tem2 = getByte();
	getByte();
	
	hwlib::cout << "The temperature in C is: " << tem1 + offset << "," << tem2 << hwlib::endl;
	return tem1 + offset;
};

float temperature::tempF(){
	float c = tempC();
	c = c*1.8 + 32;
	hwlib::cout << "The temperature in F is: " << int(c) << hwlib::endl;
	return c;
};

int temperature::tempG(){
	int c = tempC();
	c /= 3;
	hwlib::cout << "The temperature on a scale of 1 to 10 is: " << c << hwlib::endl;
	return c;
};