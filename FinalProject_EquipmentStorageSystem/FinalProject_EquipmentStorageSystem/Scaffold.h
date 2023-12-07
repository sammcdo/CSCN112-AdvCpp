#include <iostream>

#include "Equipment.h"

#pragma once


class Scaffold : public Equipment {
	/*
	* Overload << for printing a scaffold
	*/
	friend std::ostream& operator<<(std::ostream& stream, Scaffold& s);
public:
	/*
	* Construct a new scaffold
	*/
	Scaffold();

	/*
	* Create a new Scaffold using an existing scaffold
	*/
	Scaffold(const Scaffold& old);

	/*
	* Destruct a scaffold
	*/
	~Scaffold();

	/*
	* Get the length of the scaffold
	* Return:
	* The length of the scaffold
	*/
	float getLength() const;

	/*
	* Change the length of the scaffold
	* Params:
	* The new length of the scaffold
	*/
	void setLength(float length);
	
	/*
	* Get the width of the scaffold
	* Return:
	* The width of the scaffold
	*/
	float getWidth() const;

	/*
	* Change the width of the scaffold
	* Params:
	* width - The width of the scaffold
	*/
	void setWidth(float width);

	/*
	* Get the height of the scaffold
	* Return:
	* The height of the scaffold
	*/
	float getHeight() const;

	/*
	* Change the height of the scaffold
	* Params:
	* height - The new height of the scaffold
	*/
	void setHeight(float height);
	
	/*
	* Get the weight limit
	* Return:
	* The weight limit
	*/
	int getWeightLimit() const;

	/*
	* Change the weight limit of the scaffold
	* Params:
	* weightLimit - The new weight limit of the scaffold
	*/
	void setWeightLimit(int weightLimit);


private:
	float length;
	float width;
	float height;
	int weightLimit;
};