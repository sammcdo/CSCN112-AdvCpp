#include "house.h"
#include <iostream>
#include <string>



house::house(std::string c, int d, int w)
{
	setColor(c);
	setNumDoors(d);
	setNumWindows(w);
}

house::~house() {
	std::cout << "IN the destructor" << std::endl;
}

//setters
void house::setColor(std::string c)
{
	color = c;
}

void house::setNumDoors(int d)
{
	if (d < 0)
		std::cout << "The number of doors cannot be negative." << std::endl;
	else
		numDoors = d;
}

void house::setNumWindows(int w)
{
	if (w < 0)
		std::cout << "The number of windows cannot be negative." << std::endl;
	else
		numWindows = w;
}

//getters
std::string house::getColor() const
{
	return color;
}
int house::getNumDoors() const { return numDoors; }
int house::getNumWindows() const { return numWindows; }
