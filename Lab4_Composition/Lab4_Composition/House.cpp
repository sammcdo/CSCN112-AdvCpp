// Lab 4: Painting Invoice System
// Name: Sam McDowell
// Date: 10/11/2023

#include "House.h"
#include "Room.h"
#include <iostream>
#include <iomanip>
#include <vector>


/*
* Create a new House
*/
House::House() {
	setOwnerName("");
	setDistanceAway(0.0);
	setMaxRooms(0);
}

/*
* Create a new House
* Parameters:
* name - The name of the owner
* d - The distance in miles from the paint shop to the house
* r - The maximum number of Rooms that could be painted in the House
*/
House::House(std::string name, double d, int r) {
	setOwnerName(name);
	setDistanceAway(d);
	setMaxRooms(r);
}

/*
* Change the name of the owner of the House.
* Parameters:
* n - The new name of the owner
*/
void House::setOwnerName(std::string n) {
	ownerName = n;
}

/*
* Change the distance from the shop to the House.
* This should be in miles.
* Parameters:
* d - The distance to the House
* Return:
* Whether the distance was stored.
*/
bool House::setDistanceAway(double d) {
	if (d < 0) {
		// Distance cannot be 0
		return 0;
	}
	else {
		distanceAway = d;
		return 1;
	}
}

/*
* Change the maximum number of paintable rooms.
* Parameters:
* r - The maximum number of paintable rooms.
* Return:
* Whether the number of rooms was stored.
*/
bool House::setMaxRooms(int r) {
	if (r < 0) {
		// Number of Rooms cannot be negative
		return 0;
	}
	else {
		maxRooms = r;
		return 1;
	}
}

/*
* Get the name of the owner of the House
* Return:
* The name of the owner of the House.
*/
std::string House::getOwnerName() const {
	return ownerName;
}

/*
* Get the travel distance to the House.
* Return:
* The distance to the House
*/
double House::getDistance() const {
	return distanceAway;
}

/*
* Get the number of paintable rooms in the House.
* Return:
* The maximum number of paintable rooms.
*/
int House::getMaxRooms() const {
	return maxRooms;
}

/*
* Get the number of Rooms currently stored for invoicing
* Return:
* The number of stored rooms.
*/
int House::getNumberOfRooms() const {
	return rooms.size();
}

/*
* Get the number of coats of paint needed for
* all the rooms being painted.
* Return:
* The number of coats of paint.
*/
int House::getTotalNumOfCoats() const {
	int sum = 0;
	for (int i = 0; i < getNumberOfRooms(); i++) {
		sum = sum + rooms[i].getCoats();
	}
	return sum;
}

/*
* Get a Room by its ID. The IDs range from
* 0 to getNumberOfRooms() - 1 and represent the
* order the rooms were stored to be invoiced.
* Parameters:
* id - The id of the Room requested.
* Return:
* The room at the given ID.
*/
Room House::getRoomById(int id) const {
	return rooms[id];
}

/*
* Add a Room to be invoiced.
* Parameters:
* room - The room to be invoiced
* Return:
* Whether the room could be saved to the house.
*/
bool House::addRoom(Room room) {
	if (getNumberOfRooms() >= getMaxRooms()) {
		return 0;
	}
	else {
		this->rooms.push_back(room);
		return 1;
	}
}

/*
* Prints the Rooms currently stored in the house
* to the given output stream.
* Parameters:
* stream - The ostream to print data to
*/
void House::printRooms(std::ostream& stream) {
	for (int i = 0; i < getNumberOfRooms(); i++) {
		rooms[i].showData(stream);
	}
}
