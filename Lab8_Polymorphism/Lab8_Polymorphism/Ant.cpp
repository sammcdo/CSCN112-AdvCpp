// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#include <iostream>

#include "Insect.h"
#include "Ant.h"

/*
* Ant Default Constructor
*/
Ant::Ant() {
	std::cout << "Invoking Ant Default Constructor\n";
}

/*
* Ant 2 Argument Constructor
*/
Ant::Ant(std::string color="", double size=0.0) : Insect(color, size) {
	std::cout << "Invoking 2 Argument Ant Constructor\n";
}

/*
* Ant Destructor
*/
Ant::~Ant() {
	std::cout << "Invoking Ant Destructor\n";
}

/*
* Ant eat implementation
*/
void Ant::eat() {
	std::cout << "As an Ant, I eat everything.\n";
}