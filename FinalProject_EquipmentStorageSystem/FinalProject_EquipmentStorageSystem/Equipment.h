#include <iostream>
#include <string>

#include "Date.h"

#pragma once

class Equipment {

	friend std::ostream& operator<<(std::ostream& stream, Equipment& e);

public:
	/*
	* Create a new piece of equipment
	*/
	Equipment();

	/*
	* Create a new piece of equipment by copying another piece of equipment
	*/
	Equipment(const Equipment& old);

	/*
	* Destruct a piece of equipment
	*/
	~Equipment();

	/*
	* Get the ID of a piece of equipment
	* Return:
	* The ID of the equipment
	*/
	std::string getID() const;

	/*
	* Change the ID of the equipment
	* Params:
	* ID - The id of the equipment
	*/
	void setID(std::string ID);
	
	/*
	* Get the cost of the piece of equipment
	* Return:
	* The cost of the equipment
	*/
	double getCost() const;

	/*
	* Change the cost of the piece of equipment
	* Params:
	* cost - The new cost of the equipment
	*/
	void setCost(double cost);

	/*
	* Get the date the equipment was purchased
	* Return:
	* The date the equipment was purchased
	*/
	Date getDatePurchased() const;

	/*
	* Change the date the equipment was purchased
	* Params:
	* purchased - The new purchase date
	*/
	void setDatePurchased(Date purchased);

	/*
	* Get the useful life of the piece of equipment
	* Return:
	* The useful life of the equipment
	*/
	int getUsefulLife() const;

	/*
	* Change the useful life of a piece of equipment
	* Params:
	* usefulLife - The new useful life of the equipment in 
	*/
	void setUsefulLife(int usefulLife);

	/*
	* Overload the < operator for sorting
	*/
	bool operator<(const Equipment& b) const;

	/*
	* Overload the = operator for assignment
	*/
	Equipment& operator=(const Equipment& b);

private:
	std::string* ID;
	double cost;
	Date datePurchased;
	int usefulLife;
};