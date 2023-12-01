// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Faculty.h"
#include "Course.h"

/*
* Create a new Course
* The course name defaults to ""
* and the capacity defaults to 0
*/
Course::Course() {
	setName("");
	setCapacity(0);
	faculty = NULL;
	students = new std::vector<Student>;
}

/*
* Destruct the Course
*/
Course::~Course() {
	delete faculty;
	faculty = NULL;
	delete students;
	students = NULL;
}

/*
* Set the name of the Course
* Params:
* name - the name of the Course
*/
void Course::setName(std::string name) {
	this->name = name;
}

/*
* Get the name of the Course
* Return:
* The name of the Course
*/
std::string Course::getName() const {
	return name;
}

/*
* Set the Faculty member for the Course
* Params:
* faculty - The faculty member teaching the Course
*/
void Course::setFaculty(Faculty* faculty) {
	this->faculty = faculty;
}

/*
* Get the Faculty of the Course
* Return:
* The Faculty member
*/
Faculty* Course::getFaculty() const {
	return faculty;
}

/*
* Check if the class is full
* Return:
* True if it is full, otherwise false
*/
bool Course::isClassFull() const {
	if (students->size() < capacity) {
		return false;
	}
	else {
		return true;
	}
}

/*
* Add a student to the Course.
* This will not add the student if the course is full.
* It also sorts the list of students.
*/
void Course::addStudent(Student student) {
	if (!isClassFull()) {
		students->push_back(student);
		sort(students->begin(), students->end());
	}
}

/*
* Clear the list of students
*/
void Course::clearStudents() {
	students->clear();
}

/*
* Set the capacity for the Course
* Params:
* capacity - The capacity of the Course
*/
bool Course::setCapacity(int capacity) {
	if (capacity < 0) {
		return false;
	}
	else {
		this->capacity = capacity;
		return true;
	}
}

/*
* Get the capacity of the course
* Return:
* The capacity of the course
*/
int Course::getCapacity() const {
	return capacity;
}

/*
* Print a Course by overloading the << operator
*/
std::ostream& operator<<(std::ostream& stream, Course& course) {
	stream << "Information for Course " << course.getName() << ":\n" << std::endl;

	if (course.faculty != NULL) {
		stream << "Instructor:" << std::endl;
		stream << *course.getFaculty() << std::endl;
	}
	else {
		stream << "No instructor is assigned to this course." << std::endl;
	}

	stream << std::endl;

	if (course.students->size() > 0) {
		stream << "These are the students enrolled in the " << course.getName() << " course\n";
		for (int i = 0; i < course.students->size(); i++) {
			stream << (*course.students)[i] << std::endl;
		}
		stream << std::endl;
	}
	else {
		stream << "No students are enrolled in the course\n";
	}

	return stream;
}