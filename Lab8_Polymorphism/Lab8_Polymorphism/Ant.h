// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#pragma once

#include <string>
#include "Insect.h"

class Ant : public Insect {
public:
	/*
	* Ant Default Constructor
	*/
	Ant();

	/*
	* Ant 2 Argument Constructor
	*/
	Ant(std::string color, double size);

	/*
	* Ant Destructor
	*/
	~Ant();

	/*
	* Ant eat implementation
	*/
	void eat();
};