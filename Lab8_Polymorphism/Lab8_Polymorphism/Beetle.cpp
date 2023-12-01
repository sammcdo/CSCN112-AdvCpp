// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#include <iostream>

#include "Insect.h"
#include "Beetle.h"

/*
* Beetle Default Constructor
*/
Beetle::Beetle() {
	std::cout << "Invoking Beetle Default Constructor\n";
}

/*
* Beetle 2 Argument Constructor
*/
Beetle::Beetle(std::string color="", double size=0.0) : Insect(color, size) {
	std::cout << "Invoking 2 Argument Beetle Constructor\n";
}

/*
* Beetle Destructor
*/
Beetle::~Beetle() {
	std::cout << "Invoking Beetle Destructor\n";
}

/*
* Beetle eat implementation
*/
void Beetle::eat() {
	std::cout << "As an Beetle, I eat plants and small insects.\n";
}