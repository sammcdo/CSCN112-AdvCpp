// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#pragma once

#include <string>
#include "Insect.h"

class Termite : public Insect {
public:
	/*
	* Termite Default Constructor
	*/
	Termite();

	/*
	* Termite 2 Argument Constructor
	*/
	Termite(std::string color, double size);

	/*
	* Termite Destructor
	*/
	~Termite();

	/*
	* Termite eat implementation
	*/
	void eat();
};