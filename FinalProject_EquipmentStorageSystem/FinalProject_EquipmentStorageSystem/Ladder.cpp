#include <iostream>
#include <iomanip>
#include <string>

#include "Ladder.h"
#include "Equipment.h"
#include "NegativeNumberException.h"

/*
* Create a new ladder
*/
Ladder::Ladder() {
	setHeight(0);
	setStyle("");
	setWeightLimit(0);
}

/*
* Create a new ladder based on an existing ladder
*/
Ladder::Ladder(const Ladder& old) : Equipment(old) {
	setHeight(old.getHeight());
	setStyle(old.getStyle());
	setWeightLimit(old.getWeightLimit());
}

/*
* Destruct a ladder
*/
Ladder::~Ladder() {
}

/*
* Get the height of a ladder
* Return:
* The height of the ladder
*/
float Ladder::getHeight() const {
	return height;
}

/*
* Change the height of the ladder
* Params:
* height - The height of the ladder
*/
void Ladder::setHeight(float height) {
	if (height < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->height = height;
	}
}

/*
* Get the style of the ladder
* Return:
* The style of the ladder
*/
std::string Ladder::getStyle() const {
	return style;
}

/*
* Change the style of the ladder
* Params:
* style - The new style of the ladder
*/
void Ladder::setStyle(std::string style) {
	this->style = style;
}

/*
* Get the weight limit of the ladder
* Return:
* The weight limit of the ladder
*/
int Ladder::getWeightLimit() const {
	return weightLimit;
}

/*
* Change the weight limit of the ladder
* Params:
* limit - The new weight limit of the ladder
*/
void Ladder::setWeightLimit(int weightLimit) {
	if (weightLimit < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->weightLimit = weightLimit;
	}
}

/*
* Overload the << operator to print a ladder
*/
std::ostream& operator<<(std::ostream& stream, Ladder& l) {
	stream << static_cast<Equipment&>(l);

	stream << std::left << std::setw(30) << "Ladder Height:" << std::fixed << std::setprecision(2) << l.getHeight() << std::endl;
	stream << std::left << std::setw(30) << "Style:" << l.getStyle() << std::endl;
	stream << std::left << std::setw(30) << "Weight Limit:" << l.getWeightLimit() << std::endl;

	return stream;
}