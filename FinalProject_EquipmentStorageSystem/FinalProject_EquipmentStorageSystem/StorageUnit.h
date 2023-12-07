#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Equipment.h"

#pragma once

template <class T>
class StorageUnit {
	/*
	* Overload << for printing a storage unit
	*/
	template <class T>
	friend std::ostream& operator<<(std::ostream& stream, StorageUnit<T>& s);

public:
	/*
	* Create a new storage unit
	*/
	StorageUnit();

	/*
	* Destruct a storage unit
	*/
	~StorageUnit();

	/*
	* Get the unit ID of the storage unit
	* Return:
	* The unit ID of the storage unit
	*/
	std::string getUnitID() const;

	/*
	* Change the unit ID of the storage unit
	* Params:
	* unitID - The new unit ID of the storage unit
	*/
	void setUnitID(std::string unitID);

	/*
	* Get the description of the storage unit
	* Return:
	* The description of the storage unit
	*/
	std::string getDescription() const;

	/*
	* Change the description of the storage unit
	* Params:
	* description - The new description of the unit
	*/
	void setDescription(std::string description);

	/*
	* Get the length of the storage unit
	* Return:
	* The length of the storage unit
	*/
	float getLength() const;

	/*
	* Change the length of the storage unit
	* Params:
	* The new length of the storage unit
	*/
	void setLength(float length);

	/*
	* Get the width of the storage unit
	* Return:
	* The width of the storage unit
	*/
	float getWidth() const;

	/*
	* Change the width of the storage unit
	* Params:
	* width - The width of the storage unit
	*/
	void setWidth(float width);

	/*
	* Get the height of the storage unit
	* Return:
	* The height of the storage unit
	*/
	float getHeight() const;

	/*
	* Change the height of the storage unit
	* Params:
	* height - The new height of the storage unit
	*/
	void setHeight(float height);

	/*
	* Get the cost per month for the unit
	* Return:
	* The cost per month
	*/
	double getCostPerMonth();

	/*
	* Change the cost per month of the unit
	* Params:
	* costPerMonth - The cost per month
	*/
	void setCostPerMonth(double costPerMonth);

	/*
	* Get the rental contract signing date of the storage unit
	* Return:
	* The date the storage contract was signed
	*/
	Date getRentalContractDate() const;

	/*
	* Change the rental contract signing date
	* Params:
	* rentalContractDate - The new rental contract date
	*/
	void setRentalContractDate(Date rentalContractDate);

	/*
	* Get whether the storage unit auto-renews
	* Return:
	* True if the storage unit contract auto renews
	*/
	bool getAutoRenew() const;

	/*
	* Change the auto-renewal of the storage unit
	* Params:
	* autoRenew - Set to true to enable automatic renewal
	*/
	void setAutoRenew(bool autoRenew);

	/*
	* Get whether the storage unit has humidity control
	* Return:
	* True if the storage unit has humidity control
	*/
	bool getHumidityControlled() const;

	/*
	* Update whether the storage unit has humidity control
	* Params:
	* isHumidityControlled - True for humidity control
	*/
	void setHumidityControlled(bool isHumidityControlled);

	/*
	* Add a piece of equipment to the storage unit
	* Params:
	* equipment - The piece of equipment to store
	*/
	void addEquipment(T newPiece);

	/*
	* Remove an item from the storage unit by ID
	* Params:
	* id - The ID of the item to remove
	*/
	void removeInventory(std::string id);

	/*
	* Print the inventory of the storage container
	*/
	void printInventory();

private:
	std::string unitID;
	std::string description;

	float length;
	float width;
	float height;
	double costPerMonth;

	Date rentalContractDate;
	bool autoRenew;
	bool isHumidityControlled;

	std::vector<T>  equipment;
};