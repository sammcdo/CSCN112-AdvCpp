// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023


#include <string>
#include "Person.h"
#include "Date.h"

/*
* Create a new Person
*/
Person::Person() {
	setID("");
	setFirstName("");
	setLastName("");
}

/*
* Destruct a Person
*/
Person::~Person() {}

/*
* Get the ID of the person
* Return:
* The ID of the person
*/
std::string Person::getID() const {
	return ID;
}

/*
* Change the ID of the person
* Params:
* ID - The new ID of the person
*/
void Person::setID(std::string ID) {
	this->ID = ID;
}

/*
* Get the first name of the person
* Return:
* The first name of the person
*/
std::string Person::getFirstName() const {
	return fname;
}

/*
* Change the first name of the person
* Params:
* fname - The new first name of the person
*/
void Person::setFirstName(std::string fname) {
	this->fname = fname;
}

/*
* Get the last name of the person
* Return:
* The last name of the person
*/
std::string Person::getLastName() const {
	return lname;
}

/*
* Change the last name of the person
* Params:
* lname - The new last name of the person
*/
void Person::setLastName(std::string lname) {
	this->lname = lname;
}

/*
* Get the Person's birthday
* Return:
* The person's birthday
*/
Date Person::getBirthday() const {
	return birthday;
}

/*
* Set the Person's birthday
* Params:
* birthday - The new birthday
*/
void Person::setBirthday(Date birthday) {
	this->birthday = birthday;
}