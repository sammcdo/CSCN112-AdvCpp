#include <iostream>
#include <iomanip>

#include "Scaffold.h"
#include "Equipment.h"
#include "NegativeNumberException.h"

/*
* Construct a new scaffold
*/
Scaffold::Scaffold() {
	setLength(0);
	setHeight(0);
	setWidth(0);
	setWeightLimit(0);
}

/*
* Create a new Scaffold using an existing scaffold
*/
Scaffold::Scaffold(const Scaffold& old) : Equipment(old) {
	setWidth(old.getWidth());
	setLength(old.getLength());
	setHeight(old.getHeight());
	setWeightLimit(old.getWeightLimit());
}

/*
* Destruct a scaffold
*/
Scaffold::~Scaffold() {
}

/*
* Get the length of the scaffold
* Return:
* The length of the scaffold
*/
float Scaffold::getLength() const {
	return length;
}

/*
* Change the length of the scaffold
* Params:
* The new length of the scaffold
*/
void Scaffold::setLength(float length) {
	if (length < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->length = length;
	}
}

/*
* Get the width of the scaffold
* Return:
* The width of the scaffold
*/
float Scaffold::getWidth() const {
	return width;
}

/*
* Change the width of the scaffold
* Params:
* width - The width of the scaffold
*/
void Scaffold::setWidth(float width) {
	if (width < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->width = width;
	}
}

/*
* Get the height of the scaffold
* Return:
* The height of the scaffold
*/
float Scaffold::getHeight() const {
	return height;
}

/*
* Change the height of the scaffold
* Params:
* height - The new height of the scaffold
*/
void Scaffold::setHeight(float height) {
	if (height < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->height = height;
	}
}

/*
* Get the weight limit
* Return:
* The weight limit
*/
int Scaffold::getWeightLimit() const {
	return weightLimit;
}

/*
* Change the weight limit of the scaffold
* Params:
* weightLimit - The new weight limit of the scaffold
*/
void Scaffold::setWeightLimit(int weightLimit) {
	if (weightLimit < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->weightLimit = weightLimit;
	}
}

/*
* Overload the << operator to print a scaffold
*/
std::ostream& operator<<(std::ostream& stream, Scaffold& s) {
	stream << static_cast<Equipment&>(s);

	stream << std::left << std::setw(30) << "Length:" << s.getLength() << std::endl;
	stream << std::left << std::setw(30) << "Width:" << s.getWidth() << std::endl;
	stream << std::left << std::setw(30) << "Height:" << s.getHeight() << std::endl;
	stream << std::left << std::setw(30) << "Weight Limit:" << s.getWeightLimit() << std::endl;

	return stream;
}