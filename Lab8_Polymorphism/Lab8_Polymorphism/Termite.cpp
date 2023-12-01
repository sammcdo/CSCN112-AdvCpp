// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#include <iostream>

#include "Insect.h"
#include "Termite.h"

/*
* Termite Default Constructor
*/
Termite::Termite() {
	std::cout << "Invoking Termite Default Constructor\n";
}

/*
* Termite 2 Argument Constructor
*/
Termite::Termite(std::string color="", double size=0.0) : Insect(color, size) {
	std::cout << "Invoking 2 Argument Termite Constructor\n";
}

/*
* Termite Destructor
*/
Termite::~Termite() {
	std::cout << "Invoking Termite Destructor\n";
}

/*
* Termite eat implementation
*/
void Termite::eat() {
	std::cout << "As an Termite, I eat wood.\n";
}