// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#pragma once

#include <string>
#include "Insect.h"

class Beetle : public Insect {
public:
	/*
	* Beetle Default Constructor
	*/
	Beetle();

	/*
	* Beetle 2 Argument Constructor
	*/
	Beetle(std::string color, double size);

	/*
	* Beetle Destructor
	*/
	~Beetle();

	/*
	* Beetle eat implementation
	*/
	void eat();
};