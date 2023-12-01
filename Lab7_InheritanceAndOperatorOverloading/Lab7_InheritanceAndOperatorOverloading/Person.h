// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#pragma once

#include <string>
#include "Date.h"

class Person {
public:
	/*
	* Create a new Person
	*/
	Person();

	/*
	* Destruct a Person
	*/
	~Person();

	/*
	* Get the ID of the person
	* Return:
	* The ID of the person
	*/
	std::string getID() const;

	/*
	* Change the ID of the person
	* Params:
	* ID - The new ID of the person
	*/
	void setID(std::string ID);

	/*
	* Get the first name of the person
	* Return:
	* The first name of the person
	*/
	std::string getFirstName() const;

	/*
	* Change the first name of the person
	* Params:
	* fname - The new first name of the person
	*/
	void setFirstName(std::string fname);

	/*
	* Get the last name of the person
	* Return:
	* The last name of the person
	*/
	std::string getLastName() const;

	/*
	* Change the last name of the person
	* Params:
	* lname - The new last name of the person
	*/
	void setLastName(std::string lname);

	/*
	* Get the Person's birthday
	* Return:
	* The person's birthday
	*/
	Date getBirthday() const;

	/*
	* Set the Person's birthday
	* Params:
	* birthday - The new birthday
	*/
	void setBirthday(Date birthday);


private:
	std::string ID;
	std::string fname;
	std::string lname;
	Date birthday;
};
