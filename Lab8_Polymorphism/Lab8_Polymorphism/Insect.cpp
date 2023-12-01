// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#include <iostream>
#include <iomanip>
#include "Insect.h"

/*
* Create a new Insect
*/
Insect::Insect() {
	color = "";
	size = 0;

	std::cout << "Invoking the default Insect Constructor\n";
}

/*
* Create a new Insect
* Params:
* color - The color of the insect
* size - The size of the insect
*/
Insect::Insect(std::string color, double size) {
	this->color = color;
	this->size = size;

	std::cout << "Invoking 2 argument Insect Constructor\n";
}

/*
* Destruct an insect
*/
Insect::~Insect() {
	std::cout << "Invoking Insect Destructor\n";
}

/*
* Get the color of the insect
* Return:
* The color of the insect
*/
std::string Insect::getColor() {
	return color;
}

/*
* Change the color of the insect
* Params:
* color - The new color of the insect
*/
void Insect::setColor(std::string color) {
	this->color = color;
}

/*
* Get the size of the insect
* Return:
* The size of the insect
*/
double Insect::getSize() {
	return size;
}

/*
* Change the size of the insect
* Params:
* size - The new size of the insect
*/
void Insect::setSize(double size) {
	this->size = size;
}

/*
* Allow an insect to be printed by overloading the << operator
* It will output the color and size.
*/
std::ostream& operator<<(std::ostream& stream, Insect& insect) {
	stream << "My color is " << insect.getColor() 
		<< " and I am " << std::fixed << std::setprecision(2) 
		<< insect.getSize() << " millimeters long.\n";

	return stream;
}