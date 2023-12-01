// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#pragma once

#include "Person.h"
#include "Date.h"

class Faculty : public Person {

	friend std::ostream& operator<<(std::ostream& stream, Faculty& faculty);

public:
	/*
	* Create a new Faculty member
	*/
	Faculty();

	/*
	* Destruct a Faculty member
	*/
	~Faculty();

	/*
	* Get the date the faculty member was hired
	* Return:
	* The date they were hired
	*/
	Date getDateHired() const;

	/*
	* Change the date the faculty member was hired
	* Params:
	* date - The date they were hired
	*/
	void setDateHired(Date date);

	/*
	* Get the title of the faculty
	* Return:
	* The title of the faculty member
	*/
	std::string getTitle() const;

	/*
	* Change the title of the faculty
	* Params:
	* title - The new title of the faculty member
	*/
	void setTitle(std::string title);

	/*
	* Get the rank of the faculty
	* Return:
	* The rank of the faculty member
	*/
	std::string getRank() const;

	/*
	* Change the rank of the faculty
	* Params:
	* rank - The new rank of the faculty member
	*/
	void setRank(std::string rank);

	/*
	* Get the salary of the faculty
	* Return:
	* The salary of the faculty
	*/
	double getSalary() const;

	/*
	* Change the salary of the faculty
	* Params:
	* salary - The new salary of the faculty member
	* Return:
	* Whether the salary was updated
	*/
	bool setSalary(double salary);

private:
	Date dateHired;
	std::string title;
	std::string rank;
	double salary;
};