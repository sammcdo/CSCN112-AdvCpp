// Lab 4: Painting Invoice System
// Name: Sam McDowell
// Date: 10/11/2023

#pragma once

#include "Room.h"
#include <iostream>
#include <vector>

/*
* An object representing a House to be painted.
*/
class House {
public:
	/*
	* Create a new House
	*/
	House();

	/*
	* Create a new House
	* Parameters:
	* name - The name of the owner
	* d - The distance in miles from the paint shop to the house
	* r - The maximum number of Rooms that could be painted in the House
	*/
	House(std::string name, double d, int r);

	/*
	* Change the name of the owner of the House.
	* Parameters:
	* n - The new name of the owner
	*/
	void setOwnerName(std::string n);

	/*
	* Change the distance from the shop to the House.
	* This should be in miles.
	* Parameters:
	* d - The distance to the House
	* Return:
	* Whether the distance was stored.
	*/
	bool setDistanceAway(double d);

	/*
	* Change the maximum number of paintable rooms.
	* Parameters:
	* r - The maximum number of paintable rooms.
	* Return:
	* Whether the number of rooms was stored.
	*/
	bool setMaxRooms(int r);

	/*
	* Get the name of the owner of the House
	* Return:
	* The name of the owner of the House.
	*/
	std::string getOwnerName() const;

	/*
	* Get the travel distance to the House.
	* Return:
	* The distance to the House
	*/
	double getDistance() const;

	/*
	* Get the number of paintable rooms in the House.
	* Return:
	* The maximum number of paintable rooms.
	*/
	int getMaxRooms() const;

	/*
	* Get the number of Rooms currently stored for invoicing
	* Return:
	* The number of stored rooms.
	*/
	int getNumberOfRooms() const;

	/*
	* Get the number of coats of paint needed for 
	* all the rooms being painted.
	* Return:
	* The number of coats of paint.
	*/
	int getTotalNumOfCoats() const;

	/*
	* Get a Room by its ID. The IDs range from
	* 0 to getNumberOfRooms() - 1 and represent the
	* order the rooms were stored to be invoiced.
	* Parameters:
	* id - The id of the Room requested.
	* Return:
	* The room at the given ID.
	*/
	Room getRoomById(int id) const;

	/*
	* Add a Room to be invoiced.
	* Parameters:
	* room - The room to be invoiced
	* Return:
	* Whether the room could be saved to the house.
	*/
	bool addRoom(Room room);

	/*
	* Prints the Rooms currently stored in the house
	* to the given output stream.
	* Parameters:
	* stream - The ostream to print data to
	*/
	void printRooms(std::ostream& stream);


private:
	std::string ownerName;
	double distanceAway;
	int maxRooms;

	std::vector<Room> rooms;
};
