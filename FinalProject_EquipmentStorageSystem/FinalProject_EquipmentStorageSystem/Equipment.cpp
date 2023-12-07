#include <iostream>
#include <iomanip>
#include <string>

#include "Equipment.h"
#include "Date.h"
#include "NegativeNumberException.h"

/*
* Create a new piece of equipment
*/
Equipment::Equipment() {
	ID = new std::string("");
	
	setCost(0);
	
	Date init;
	setDatePurchased(init);

	setUsefulLife(0);

}

/*
* Create a new piece of equipment by copying another piece of equipment
*/
Equipment::Equipment(const Equipment& old) {
	ID = new std::string;
	setID(old.getID());

	setCost(old.getCost());

	setDatePurchased(old.getDatePurchased());

	setUsefulLife(old.getUsefulLife());

}

/*
* Destruct a piece of equipment
*/
Equipment::~Equipment() {
	delete ID;
	ID = NULL;
}

/*
* Get the ID of a piece of equipment
* Return:
* The ID of the equipment
*/
std::string Equipment::getID() const {
	return *ID;
}

/*
* Change the ID of the equipment
* Params:
* ID - The id of the equipment
*/
void Equipment::setID(std::string ID) {
	*(this->ID) = ID;
}

/*
* Get the cost of the piece of equipment
* Return:
* The cost of the equipment
*/
double Equipment::getCost() const {
	return cost;
}

/*
* Change the cost of the piece of equipment
* Params:
* cost - The new cost of the equipment
*/
void Equipment::setCost(double cost) {
	if (cost < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->cost = cost;
	}
}

/*
* Get the date the equipment was purchased
* Return:
* The date the equipment was purchased
*/
Date Equipment::getDatePurchased() const {
	return datePurchased;
}

/*
* Change the date the equipment was purchased
* Params:
* purchased - The new purchase date
*/
void Equipment::setDatePurchased(Date purchased) {
	this->datePurchased = purchased;
}

/*
* Get the useful life of the piece of equipment
* Return:
* The useful life of the equipment
*/
int Equipment::getUsefulLife() const {
	return usefulLife;
}

/*
* Change the useful life of a piece of equipment
* Params:
* usefulLife - The new useful life of the equipment in
*/
void Equipment::setUsefulLife(int usefulLife) {
	if (usefulLife < 0) {
		throw new NegativeNumberException;
	}
	else {
		this->usefulLife = usefulLife;
	}
}

/*
* Overload the < operator for sorting
*/
bool Equipment::operator<(const Equipment& b) const {
	return getID() < b.getID();
}

/*
* Overload the = operator for assignment
*/
Equipment& Equipment::operator=(const Equipment& b) {
	Equipment e;
	e.setID(b.getID());
	e.setCost(b.getCost());
	e.setDatePurchased(b.getDatePurchased());
	e.setUsefulLife(b.getUsefulLife());

	return e;
}

/*
* Overload the << operator so a piece of equipment can be printed
*/
std::ostream& operator<<(std::ostream& stream, Equipment& e) {
	stream << std::left << std::setw(30) << "ID Number:" << e.getID() << std::endl;
	stream << std::left << std::setw(30) << "Original Cost:" << std::fixed << std::setprecision(2) << e.getCost() << std::endl;
	stream << std::left << std::setw(30) << "Date Purchased:" << e.getDatePurchased() << std::endl;
	stream << std::left << std::setw(30) << "Useful Life:" << e.getUsefulLife() << std::endl;

	return stream;
}