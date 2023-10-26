// Lab 4: Painting Invoice System
// Name: Sam McDowell
// Date: 10/11/2023

#pragma once

#include <iostream>

class Room {
public:
	/* The number of square feet per gallon paint used */
	const int SQ_FEET_PER_GALLON_PAINT = 400;

	/*
	* Create a new Room
	*/
	Room();

	/*
	* Create a new Room
	* Parameters:
	* l - The length of the Room
	* w - The width of the Room
	* h - The height of the Room
	* c - The number of coats to paint the Room
	*/
	Room(double l, double w, double h, double c);

	// Setters

	/*
	* Set the length of the Room.
	* The length must be a positive double or it will set unsuccessfully.
	* Parameters:
	* l - The new length of the room
	* Return:
	* Whether the length was set successfully 
	* (1 if it was updated, 0 if the input was invalid)
	*/
	bool setLength(double l);

	/*
	* Set the width of the Room.
	* The width must be a positive double or it will set unsuccessfully.
	* Parameters:
	* w - The new width of the room
	* Return:
	* Whether the width was set successfully
	* (1 if it was updated, 0 if the input was invalid)
	*/
	bool setWidth(double w);

	/*
	* Set the height of the Room.
	* The height must be a positive double or it will set unsuccessfully.
	* Parameters:
	* h - The new height of the room
	* Return:
	* Whether the height was set successfully
	* (1 if it was updated, 0 if the input was invalid)
	*/
	bool setHeight(double h);

	/*
	* Set the number of coats of paint for the Room.
	* The number of coats must be positive or it will set unsuccessfully.
	* Parameters:
	* c - The new number of coats of paint
	* Return
	* Whether the input was saved successfully,
	* (1 if it was updated and 0 if the input was invalid)
	*/
	bool setCoats(int c);

	// Getters

	/*
	* Get the length of the room.
	* Return:
	* The length of the room.
	*/
	double getLength() const;

	/*
	* Get the width of the room.
	* Return:
	* The width of the room.
	*/
	double getWidth() const;

	/*
	* Get the height of the room.
	* Return:
	* The height of the room.
	*/
	double getHeight() const;
	
	/*
	* Get the number of coats of paint.
	* Return:
	* The number of coats of paint to apply.
	*/
	int getCoats() const;

	// Helpers

	/*
	* Calculate the volume of the room.
	* Return:
	* The volume of the room.
	*/
	double calcVolume() const;

	/*
	* Calculate the painted area of the room.
	* Return:
	* The painted area of the room.
	*/
	double calcPaintedArea() const;

	/*
	* Calculate the number of gallons of paint that
	* will be used to paint the room.
	* Return:
	* The gallons of paint consumed
	*/
	double calcGallonsOfPaint() const;

	/*
	* Print a table of the room information.
	* This includes the dimensions, volume and painted area.
	*/
	void showData(std::ostream& stream) const;

private:
	double length{ 0 };
	double width{ 0 };
	double height{ 0 };
	double coats{ 0 };
};