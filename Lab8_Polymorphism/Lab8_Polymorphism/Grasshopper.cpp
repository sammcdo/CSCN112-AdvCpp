// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#include <iostream>

#include "Insect.h"
#include "Grasshopper.h"

/*
* Grasshopper Default Constructor
*/
Grasshopper::Grasshopper() {
	std::cout << "Invoking Grasshopper Default Constructor\n";
}

/*
* Grasshopper 2 Argument Constructor
*/
Grasshopper::Grasshopper(std::string color="", double size=0.0) : Insect(color, size) {
	std::cout << "Invoking 2 Argument Grasshopper Constructor\n";
}

/*
* Grasshopper Destructor
*/
Grasshopper::~Grasshopper() {
	std::cout << "Invoking Grasshopper Destructor\n";
}

/*
* Grasshopper eat implementation
*/
void Grasshopper::eat() {
	std::cout << "As an Grasshopper, I eat grass and leaves.\n";
}