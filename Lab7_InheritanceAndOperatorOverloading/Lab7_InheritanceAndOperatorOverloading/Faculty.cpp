// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#include <iostream>
#include <iomanip>
#include "Person.h"
#include "Date.h"
#include "Faculty.h"

/*
* Create a new Faculty member
*/
Faculty::Faculty() {
	salary = 0;
}

/*
* Destruct a Faculty member
*/
Faculty::~Faculty() {
}

/*
* Get the date the faculty member was hired
* Return:
* The date they were hired
*/
Date Faculty::getDateHired() const {
	return dateHired;
}

/*
* Change the date the faculty member was hired
* Params:
* date - The date they were hired
*/
void Faculty::setDateHired(Date date) {
	dateHired = date;
}

/*
* Get the title of the faculty
* Return:
* The title of the faculty member
*/
std::string Faculty::getTitle() const {
	return title;
}

/*
* Change the title of the faculty
* Params:
* title - The new title of the faculty member
*/
void Faculty::setTitle(std::string title) {
	this->title = title;
}

/*
* Get the rank of the faculty
* Return:
* The rank of the faculty member
*/
std::string Faculty::getRank() const {
	return rank;
}

/*
* Change the rank of the faculty
* Params:
* rank - The new rank of the faculty member
*/
void Faculty::setRank(std::string rank) {
	this->rank = rank;
}

/*
* Get the salary of the faculty
* Return:
* The salary of the faculty
*/
double Faculty::getSalary() const {
	return salary;
}

/*
* Change the salary of the faculty
* Params:
* salary - The new salary of the faculty member
* Return:
* Whether the salary was updated
*/
bool Faculty::setSalary(double salary) {
	if (salary < 0) {
		return false;
	}
	else {
		this->salary = salary;
		return true;
	}
}

/*
* Print a faculty member by overloading the << operator
*/
std::ostream& operator<<(std::ostream& stream, Faculty& faculty) {
	stream << std::left << std::setw(15)
		<< "Faculty ID:" << faculty.getID() << std::endl;
	stream << std::left << std::setw(15)
		<< "Faculty Name:" << faculty.getTitle() << " " << faculty.getFirstName() << " "
		<< faculty.getLastName() << ", " << faculty.getRank() << std::endl;
	stream << std::left << std::setw(15)
		<< "Birth Date:" << faculty.getBirthday() << std::endl;
	stream << std::left << std::setw(15)
		<< "Date Hired:" << faculty.getDateHired() << std::endl;
	stream << std::left << std::setw(15)
		<< "Salary:" << std::fixed << std::setprecision(2) << faculty.getSalary() << std::endl;

	return stream;
}