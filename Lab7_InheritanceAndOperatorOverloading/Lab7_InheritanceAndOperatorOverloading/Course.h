// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Faculty.h"

class Course {
	friend std::ostream& operator<<(std::ostream& stream, Course& course);

public:
	/*
	* Create a new Course
	* The course name defaults to ""
	* and the capacity defaults to 0
	*/
	Course();

	/*
	* Destruct the Course
	*/
	~Course();

	/*
	* Set the name of the Course
	* Params:
	* name - the name of the Course
	*/
	void setName(std::string name);

	/*
	* Get the name of the Course
	* Return:
	* The name of the Course
	*/
	std::string getName()const;

	/*
	* Set the Faculty member for the Course
	* Params:
	* faculty - The faculty member teaching the Course
	*/
	void setFaculty(Faculty* faculty);

	/*
	* Get the Faculty of the Course
	* Return:
	* The Faculty member
	*/
	Faculty* getFaculty() const;

	/*
	* Check if the class is full
	* Return:
	* True if it is full, otherwise false
	*/
	bool isClassFull() const;

	/*
	* Add a student to the Course.
	* This will not add the student if the course is full.
	* It also sorts the list of students.
	*/
	void addStudent(Student student);

	/*
	* Clear the list of students
	*/
	void clearStudents();

	/*
	* Set the capacity for the Course
	* Params:
	* capacity - The capacity of the Course
	*/
	bool setCapacity(int capacity);

	/*
	* Get the capacity of the course
	* Return:
	* The capacity of the course
	*/
	int getCapacity() const;


private:
	std::string name;
	Faculty* faculty;
	std::vector<Student>* students;
	int capacity;
};

