// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#pragma once

#include <string>
#include <iomanip>
#include "Person.h"
#include "Date.h"

class Student : public Person {
	friend std::ostream& operator<<(std::ostream& stream, Student& course);

public:
	/*
	* Create a new Student
	*/
	Student();

	/*
	* Destruct a Student
	*/
	~Student();

	/*
	* Get the date the student enrolled
	* Return:
	* The date they enrolled
	*/
	Date getDateEnrolled() const;

	/*
	* Change the date the student enrolled
	* Params:
	* date - The date they enrolled
	*/
	void setDateEnrolled(Date date);

	/*
	* Get the major of the student
	* Return:
	* The major of the student
	*/
	std::string getMajor() const;

	/*
	* Change the major of the student
	* Params:
	* major - The new major of the student
	*/
	void setMajor(std::string major);

	/*
	* Get the level of the student
	* Return:
	* The level of the student
	*/
	std::string getLevel() const;

	/*
	* Change the level of the student
	* Params:
	* level - The new level of the student
	*/
	void setLevel(std::string level);

	/*
	* Get the GPA of the student
	* Return:
	* The GPA of the student
	*/
	double getGPA() const;

	/*
	* Change the GPA of the student
	* Params:
	* gpa - The new GPA of the student
	* Return:
	* Whether the GPA was updated
	*/
	bool setGPA(double gpa);

	/*
	* Overload the < operator to allow sorting by id
	*/
	bool operator<(Student b);

private:
	Date dateEnrolled;
	std::string major;
	std::string level;
	double gpa;
};