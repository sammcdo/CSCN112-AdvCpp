#include <iostream>
#include "house.h"

using namespace std;


int main()
{
	house myHouse;
	house yourHouse("Pink", 2, 8);
	myHouse.setColor("Blue");
	myHouse.setNumDoors(3);
	myHouse.setNumWindows(20);
	cout << myHouse.getColor() << endl;
	cout << myHouse.getNumWindows() << endl;
	cout << myHouse.getNumDoors() << endl;


	cout << yourHouse.getColor() << endl;
	cout << yourHouse.getNumWindows() << endl;
	cout << yourHouse.getNumDoors() << endl;
	return 0;
}
