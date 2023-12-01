// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023


#include <string>
#include <iomanip>
#include "Date.h"
#include "Student.h"


/*
* Create a new Student
*/
Student::Student() {
	gpa = 0;
}
/*
* Destruct a Student
*/
Student::~Student() {}

/*
* Get the date the student enrolled
* Return:
* The date they enrolled
*/
Date Student::getDateEnrolled() const {
	return dateEnrolled;
}

/*
* Change the date the student enrolled
* Params:
* date - The date they enrolled
*/
void Student::setDateEnrolled(Date date) {
	dateEnrolled = date;
}

/*
* Get the major of the student
* Return:
* The major of the student
*/
std::string Student::getMajor() const {
	return major;
}

/*
* Change the major of the student
* Params:
* major - The new major of the student
*/
void Student::setMajor(std::string major) {
	this->major = major;
}

/*
* Get the level of the student
* Return:
* The level of the student
*/
std::string Student::getLevel() const {
	return level;
}

/*
* Change the level of the student
* Params:
* level - The new level of the student
*/
void Student::setLevel(std::string level) {
	this->level = level;
}

/*
* Get the GPA of the student
* Return:
* The GPA of the student
*/
double Student::getGPA() const {
	return gpa;
}

/*
* Change the GPA of the student
* Params:
* gpa - The new GPA of the student
* Return:
* Whether the GPA was updated
*/
bool Student::setGPA(double gpa) {
	if (gpa < 0) {
		return false;
	}
	else {
		this->gpa = gpa;
		return true;
	}
}

/*
* Overload the < operator to allow sorting by id
*/
bool Student::operator<(Student b) {
	return (getID() < b.getID());
}

/*
* Print a student by overloading the << operator
*/
std::ostream& operator<<(std::ostream& stream, Student& student) {
	stream << std::left << std::setw(15)
		<< "Student ID:" << student.getID() << std::endl;
	stream << std::left << std::setw(15)
		<< "Student Name:" << student.getFirstName() << " " << student.getLastName() << std::endl;
	stream << std::left << std::setw(15)
		<< "Birth Date:" << student.getBirthday() << std::endl;
	stream << std::left << std::setw(15)
		<< "Date Enrolled:" << student.getDateEnrolled() << std::endl;
	stream << std::left << std::setw(15)
		<< "Major:" << student.getMajor() << std::endl;
	stream << std::left << std::setw(15)
		<< "Level:" << student.getLevel() << std::endl;
	stream << std::left << std::setw(15)
		<< "GPA:" << student.getGPA() << std::endl;

	return stream;
}