#pragma once
#include <iostream>
#include <string>


class house
{
public:
	house(std::string c = "", int d = 0, int w = 0);
	~house();
	//setters
	void setColor(std::string c);
	void setNumDoors(int d);
	void setNumWindows(int w);
	//getters
	std::string getColor() const;
	int getNumDoors() const;
	int getNumWindows() const;
private:
	int numDoors;
	int numWindows;
	std::string color;
};
