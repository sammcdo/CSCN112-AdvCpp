// Lab 4: Painting Invoice System
// Name: Sam McDowell
// Date: 10/11/2023

#include "Room.h"
#include <iostream>
#include <iomanip>

/*
* Create a new Room.
* 
* Initialize all dimensions to 0.
*/
Room::Room() {
	setLength(0);
	setWidth(0);
	setHeight(0);
	setCoats(0);
}

/*
* Create a new Room
* Parameters:
* l - The length of the Room
* w - The width of the Room
* h - The height of the Room
* c - The number of coats to paint the Room
*/
Room::Room(double l=0, double w=0, double h=0, double c=0) {
	setLength(l);
	setWidth(w);
	setHeight(h);
	setCoats(c);
}

/*
* Set the length of the Room.
* The length must be a positive double or it will set unsuccessfully.
* Parameters:
* l - The new length of the room
* Return:
* Whether the length was set successfully
* (1 if it was updated, 0 if the input was invalid)
*/
bool Room::setLength(double l) {
	if (l < 0) {
		// Length is negative, do not update
		return 0;
	}
	else {
		// Length is valid, update
		length = l;
		return 1;
	}
}

/*
* Set the width of the Room.
* The width must be a positive double or it will set unsuccessfully.
* Parameters:
* w - The new width of the room
* Return:
* Whether the width was set successfully
* (1 if it was updated, 0 if the input was invalid)
*/
bool Room::setWidth(double w) {
	if (w < 0) {
		// Width is negative, do not update
		return 0;
	}
	else {
		// Width is valid, update
		width = w;
		return 1;
	}
}

/*
* Set the height of the Room.
* The height must be a positive double or it will set unsuccessfully.
* Parameters:
* h - The new height of the room
* Return:
* Whether the height was set successfully
* (1 if it was updated, 0 if the input was invalid)
*/
bool Room::setHeight(double h) {
	if (h < 0) {
		// Height is negative, do not update
		return 0;
	}
	else {
		// Height is valid, update
		height = h;
		return 1;
	}
}

/*
* Set the number of coats for the Room.
* The number of coats must be a positive integer or it will set unsuccessfully.
* Parameters:
* h - The new number of coats for the room
* Return:
* Whether the number of coats was set successfully
* (1 if it was updated, 0 if the input was invalid)
*/
bool Room::setCoats(int c) {
	if (c < 0) {
		// coats is negative, do not update
		return 0;
	}
	else {
		// Height is valid, update
		coats = c;
		return 1;
	}
}

/*
* Get the length of the room.
* Return:
* The length of the room.
*/
double Room::getLength() const {
	return length;
}

/*
* Get the width of the room.
* Return:
* The width of the room.
*/
double Room::getWidth() const {
	return width;
}

/*
* Get the height of the room.
* Return:
* The height of the room.
*/
double Room::getHeight() const {
	return height;
}

/*
* Get the number of coats of paint.
* Return:
* The number of coats of paint to apply.
*/
int Room::getCoats() const {
	return coats;
}

/*
* Calculate the volume of the room.
* This uses the formula l * w * h.
* Return:
* The volume of the room.
*/
double Room::calcVolume() const {
	return getLength() * getWidth() * getHeight();
}

/*
* Calculate the painted area of the room.
* This uses the formula 2(l * h) + 2(w * h).
* Return:
* The painted area of the room.
*/
double Room::calcPaintedArea() const {
	return (2 * getLength() * getHeight()) 
		+ (2 * getWidth() * getHeight());
}

/*
* Calculate the number of gallons of paint that
* will be used to paint the room.
* Return:
* The gallons of paint consumed
*/
double Room::calcGallonsOfPaint() const {
	return this->calcPaintedArea() / SQ_FEET_PER_GALLON_PAINT;
}

/*
* Print a table of the room information.
* This includes the dimensions, volume and painted area.
* 
* Use two columns for the data, all with decimal places aligned.
*/
void Room::showData(std::ostream& stream) const {
	// Print length, width, and height
	stream << "------------------------ Room Details ------------------------" << std::endl;
	stream << std::left << std::setw(20) << "Length:" << std::right 
		<< std::setw(10) << std::setprecision(2) << std::fixed << getLength() << std::endl;
	stream << std::left << std::setw(20) << "Width:" << std::right 
		<< std::setw(10) << std::setprecision(2) << std::fixed << getWidth() << std::endl;
	stream << std::left << std::setw(20) << "Height:" << std::right 
		<< std::setw(10) << std::setprecision(2) << std::fixed << getHeight() << std::endl;
	stream << std::left << std::setw(20) << "Coats:" << std::right
		<< std::setw(10) << std::setprecision(2) << std::fixed << getCoats() << std::endl;

	stream << std::endl;

	// Print calculated section
	stream << std::left << std::setw(20) << "Volume:" << std::right 
		<< std::setw(10) << std::setprecision(2) << std::fixed << calcVolume() << std::endl;
	stream << std::left << std::setw(20) << "Painted Area:" << std::right 
		<< std::setw(10) << std::setprecision(2) << std::fixed << calcPaintedArea() << std::endl;

	stream << "-- Paint Required --  " << std::fixed
		<< std::setprecision(2) << calcGallonsOfPaint()
		<< " Gallons" << std::endl;
	stream << "------------------------ ************ ------------------------" << std::endl;
}