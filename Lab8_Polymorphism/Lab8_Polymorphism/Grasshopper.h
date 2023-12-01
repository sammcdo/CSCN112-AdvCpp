// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#pragma once

#include <string>
#include "Insect.h"

class Grasshopper : public Insect {
public:
	/*
	* Grasshopper Default Constructor
	*/
	Grasshopper();

	/*
	* Grasshopper 2 Argument Constructor
	*/
	Grasshopper(std::string color, double size);

	/*
	* Grasshopper Destructor
	*/
	~Grasshopper();

	/*
	* Grasshopper eat implementation
	*/
	void eat();
};