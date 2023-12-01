// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#pragma once

#include <string>

class Insect {
	/*
	* Allow an insect to be printed by overloading the << operator
	* It will output the color and size.
	*/
	friend std::ostream& operator<<(std::ostream& stream, Insect& insect);

public:

	/*
	* Create a new Insect
	*/
	Insect();

	/*
	* Create a new Insect
	* Params:
	* color - The color of the insect
	* size - The size of the insect
	*/
	Insect(std::string color, double size);

	/*
	* Destruct an insect
	*/
	virtual ~Insect();

	/*
	* Allow the insect to eat.
	*/
	virtual void eat() = 0;

	/*
	* Get the color of the insect
	* Return:
	* The color of the insect
	*/
	std::string getColor();

	/*
	* Change the color of the insect
	* Params:
	* color - The new color of the insect
	*/
	void setColor(std::string color);

	/*
	* Get the size of the insect
	* Return:
	* The size of the insect
	*/
	double getSize();

	/*
	* Change the size of the insect
	* Params:
	* size - The new size of the insect
	*/
	void setSize(double size);
private:
	std::string color;
	double size;
};

