#include <iostream>
#include <string>

#include "Equipment.h"

#pragma once

class Ladder : public Equipment {
	/*
	* Overload << for printing a ladder
	*/
	friend std::ostream& operator<<(std::ostream& stream, Ladder& l);

public:
	/*
	* Create a new ladder
	*/
	Ladder();

	/*
	* Create a new ladder based on an existing ladder
	*/
	Ladder(const Ladder& old);

	/*
	* Destruct a ladder
	*/
	~Ladder();

	/*
	* Get the height of a ladder
	* Return:
	* The height of the ladder
	*/
	float getHeight() const;

	/*
	* Change the height of the ladder
	* Params:
	* height - The height of the ladder
	*/
	void setHeight(float height);

	/*
	* Get the style of the ladder
	* Return:
	* The style of the ladder
	*/
	std::string getStyle() const;

	/*
	* Change the style of the ladder
	* Params:
	* style - The new style of the ladder
	*/
	void setStyle(std::string style);
	
	/*
	* Get the weight limit of the ladder
	* Return:
	* The weight limit of the ladder
	*/
	int getWeightLimit() const;

	/*
	* Change the weight limit of the ladder
	* Params:
	* weightLimit - The new weight limit of the ladder
	*/
	void setWeightLimit(int weightLimit);

private:
	float height;
	std::string style;
	int weightLimit;
};