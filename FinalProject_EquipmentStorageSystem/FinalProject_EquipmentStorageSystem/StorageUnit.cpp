#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "StorageUnit.h"
#include "NegativeNumberException.h"
#include "InvalidIdException.h"
#include "ItemNotFoundException.h"

/*
* Create a new storage unit
*/
template <class T>
StorageUnit<T>::StorageUnit() {
	setUnitID("");

	setLength(0);
	setWidth(0);
	setHeight(0);
	setCostPerMonth(0);

	Date init;
	setRentalContractDate(init);

	setAutoRenew(false);
	setHumidityControlled(false);
}

/*
* Destruct a storage unit
*/
template <class T>
StorageUnit<T>::~StorageUnit() {

}

/*
* Get the unit ID of the storage unit
* Return:
* The unit ID of the storage unit
*/
template <class T>
std::string StorageUnit<T>::getUnitID() const {
	return unitID;
}

/*
* Change the unit ID of the storage unit
* Params:
* unitID - The new unit ID of the storage unit
*/
template <class T>
void StorageUnit<T>::setUnitID(std::string unitID) {
	this->unitID = unitID;
}

/*
* Get the description of the storage unit
* Return:
* The description of the storage unit
*/
template <class T>
std::string StorageUnit<T>::getDescription() const {
	return description;
}

/*
* Change the description of the storage unit
* Params:
* description - The new description of the unit
*/
template <class T>
void StorageUnit<T>::setDescription(std::string description) {
	this->description = description;
}

/*
* Get the length of the storage unit
* Return:
* The length of the storage unit
*/
template <class T>
float StorageUnit<T>::getLength() const {
	return length;
}

/*
* Change the length of the storage unit
* Params:
* The new length of the storage unit
*/
template <class T>
void StorageUnit<T>::setLength(float length) {
	if (length < 0) {
		throw NegativeNumberException();
	}
	else {
		this->length = length;
	}
}

/*
* Get the width of the storage unit
* Return:
* The width of the storage unit
*/
template <class T>
float StorageUnit<T>::getWidth() const {
	return width;
}

/*
* Change the width of the storage unit
* Params:
* width - The width of the storage unit
*/
template <class T>
void StorageUnit<T>::setWidth(float width) {
	if (width < 0) {
		throw NegativeNumberException();
	}
	else {
		this->width = width;
	}
}

/*
* Get the height of the storage unit
* Return:
* The height of the storage unit
*/
template <class T>
float StorageUnit<T>::getHeight() const {
	return height;
}

/*
* Change the height of the storage unit
* Params:
* height - The new height of the storage unit
*/
template <class T>
void StorageUnit<T>::setHeight(float height) {
	if (height < 0) {
		throw NegativeNumberException();
	}
	else {
		this->height = height;
	}
}

/*
* Get the cost per month for the unit
* Return:
* The cost per month
*/
template <class T>
double StorageUnit<T>::getCostPerMonth() {
	return costPerMonth;
}

/*
* Change the cost per month of the unit
* Params:
* costPerMonth - The cost per month
*/
template <class T>
void StorageUnit<T>::setCostPerMonth(double costPerMonth) {
	if (costPerMonth < 0) {
		throw NegativeNumberException();
	}
	else {
		this->costPerMonth = costPerMonth;
	}
}

/*
* Get the rental contract signing date of the storage unit
* Return:
* The date the storage contract was signed
*/
template <class T>
Date StorageUnit<T>::getRentalContractDate() const {
	return rentalContractDate;
}

/*
* Change the rental contract signing date
* Params:
* rentalContractDate - The new rental contract date
*/
template <class T>
void StorageUnit<T>::setRentalContractDate(Date rentalContractDate) {
	this->rentalContractDate = rentalContractDate;
}

/*
* Get whether the storage unit auto-renews
* Return:
* True if the storage unit contract auto renews
*/
template <class T>
bool StorageUnit<T>::getAutoRenew() const {
	return autoRenew;
}

/*
* Change the auto-renewal of the storage unit
* Params:
* autoRenew - Set to true to enable automatic renewal
*/
template <class T>
void StorageUnit<T>::setAutoRenew(bool autoRenew) {
	this->autoRenew = autoRenew;
}

/*
* Get whether the storage unit has humidity control
* Return:
* True if the storage unit has humidity control
*/
template <class T>
bool StorageUnit<T>::getHumidityControlled() const {
	return isHumidityControlled;
}

/*
* Update whether the storage unit has humidity control
* Params:
* isHumidityControlled - True for humidity control
*/
template <class T>
void StorageUnit<T>::setHumidityControlled(bool isHumidityControlled) {
	this->isHumidityControlled = isHumidityControlled;
}

/*
* Add a piece of equipment to the storage unit
* Make sure the ID does not exist already
* Params:
* equipment - The piece of equipment to store
*/
template <class T>
void StorageUnit<T>::addEquipment(T newPiece) {
	for (T piece : equipment) {
		if (piece.getID() == newPiece.getID()) {
			throw InvalidIdException();
		}
	}
	equipment.push_back(newPiece);
}

/*
* Remove an item from the storage unit by ID
* Params:
* id - The ID of the item to remove
*/
template <class T>
void StorageUnit<T>::removeInventory(std::string id) {
	bool found{ false };


	for (int i = 0; i < this->equipment.size(); i++) {
		if (equipment[i].getID() == id) {
			found = true;
			equipment.erase(equipment.begin()+i);
		}
	}

	if (!found) {
		throw ItemNotFoundException();
	}
}

/*
* Print the inventory of the storage container
*/
template <class T>
void StorageUnit<T>::printInventory() {
	std::sort(this->equipment.begin(), this->equipment.end());

	for (int i = 0; i < this->equipment.size(); i++) {
		std::cout << this->equipment[i] << std::endl;
	}
}

/*
* Overload the << operator to print a ladder
*/
template <class T>
std::ostream& operator<<(std::ostream& stream, StorageUnit<T>& s) {
	stream << "Storage Unit Information" << std::endl;
	stream << std::endl;
	stream << std::left << std::setw(20) << "Unit ID:"
		<< std::right << std::setw(20) << s.getUnitID() << std::endl;
	stream << std::left << std::setw(20) << "Description:" 
		<< std::right << std::setw(20) << s.getDescription() << std::endl;
	stream << "Dimensions" << std::endl;
	stream << std::left << std::setw(20) << "Length:"
		<< std::right << std::setw(20) << std::setprecision(1) << std::fixed << s.getLength() << std::endl;
	stream << std::left << std::setw(20) << "Width:"
		<< std::right << std::setw(20) << std::setprecision(1) << std::fixed << s.getWidth() << std::endl;
	stream << std::left << std::setw(20) << "Height:"
		<< std::right << std::setw(20) << std::setprecision(1) << std::fixed << s.getHeight() << std::endl;
	stream << std::endl;
	if (s.getHumidityControlled()) {
		stream << "**Unit is humidity controlled" << std::endl;
	}
	else {
		stream << "**Unit is not humidity controlled" << std::endl;
	}
	stream << std::endl;
	stream << "Rental Contract" << std::endl;
	stream << std::left << std::setw(20) << "Cost Per Month:"
		<< std::right << std::setw(20) << std::setprecision(2) << std::fixed << s.getCostPerMonth() << std::endl;
	stream << std::left << std::setw(20) << "Date Signed:"
		<< std::right << std::setw(20) << s.getRentalContractDate() << std::endl;

	stream << std::endl;
	if (s.getAutoRenew()) {
		stream << "**Unit will auto-renew" << std::endl;
	}
	else {
		stream << "**Unit will not auto-renew" << std::endl;
	}

	return stream;
}