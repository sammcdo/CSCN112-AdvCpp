// Lab 2: Painting Class
// Name: Sam McDowell
// Date: 09/15/2023

#pragma once

class Room {
public:
	/*
	* Create a new Room
	*/
	Room();

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
	* Print a table of the room information.
	* This includes the dimensions, volume and painted area.
	*/
	void showData() const;

private:
	double length{ 0 };
	double width{ 0 };
	double height{ 0 };
};