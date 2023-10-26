#include "Employee.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>


/*
* Construct an employee
* Defaults name, city, and id to empty strings
*/
Employee::Employee(std::string name, std::string city, std::string id) {
	this->setName(name);
	this->setCity(city);
	this->setID(id);
}

/*
* Destruct the employee
*/
Employee::~Employee() {
	// No special steps for destruction
}

/*
* Get the name of the employee
* Return
* The name of the employee
*/
std::string Employee::getName() const {
	return this->name;
}

/*
* Set the name of the employee
* Parameters
* name - The new name of the employee
*/
void Employee::setName(std::string name) {
	this->name = name;
}

/*
* Get the employee's city
* Return
* The employee's city
*/
std::string Employee::getCity() const {
	return this->city;
}

/*
* Set the employee's city
* Parameters
* city - The new city
*/
void Employee::setCity(std::string city) {
	this->city = city;
}

/*
* Get the ID of the employee
* Return
* The ID of the employee
*/
std::string Employee::getID() const {
	return this->id;
}

/*
* Set the employee ID
* Parameters
* id - The new ID
*/
void Employee::setID(std::string id) {
	this->id = id;
}

/*
* Get the satisfaction scores list
* Return
* The satisfaction scores
*/
std::vector<double> Employee::getScores() const {
	return this->scores;
}

/*
* Add a satisfaction score to the list.
* Output whether the input was valid (1-5)
* Parameters
* score - The score to add
* Return
* Whether the score was valid and saved - True if it was saved, false if it was not
*/
bool Employee::addScore(double score) {
	if (score >= 1 && score <= 5) {
		this->scores.push_back(score);
		return true;
	}
	else {
		return false;
	}
}

/*
* Sort the satisfaction scores list inplace
* Uses built in sort which is O(n logn) for a vector
*/
void Employee::sortScores() {
	std::sort(this->scores.begin(), this->scores.end());
}

/*
* Get the average satisfaction score.
* Formula: sum(scores) / number of scores
* Return
* The average score
*/
double Employee::getAverageScore() const {
	double sum = 0;

	for (double score : this->scores) {
		sum += score;
	}

	double average = sum / this->scores.size();

	return average;
}

/*
* Get the lowest satisfaction score
* Return
* The lowest satisfaction score
*/
double Employee::getLowestScore() const {
	double low = 6;

	// Loop through each item and check if it is the highest
	for (double i : this->scores) {
		if (i < low) {
			low = i;
		}
	}

	return low;
}

/*
* Get the highest satisfaction score.
* Return
* The highest score.
*/
double Employee::getHighestScore() const {
	double high = -1;
	
	// Loop through the scores and check if each item is the highest
	for (double i : this->scores) {
		if (i > high) {
			high = i;
		}
	}
	
	return high;
}

/*
* Get the number of scores.
* Return
* The number of scores.
*/
int Employee::getNumberOfScores() const {
	return this->scores.size();
}

/*
* Print a table of employee information.
* This includes name, city, and id.
* It also shows the satisfaction scores and
* high/low/average score information.
* 
* This function will sort the scores before output.
*/
void Employee::printEmployeeInfo() {
	// Basic table
	std::cout << "*********************************************************" << std::endl;
	std::cout << "                  Employee Information                   " << std::endl;
	std::cout << std::left << std::setw(18)
		<< "Employee Name: " << getName() << std::endl;
	std::cout << std::left << std::setw(18)
		<< "City: " << getCity() << std::endl;
	std::cout << std::left << std::setw(18)
		<< "ID: " << getID() << std::endl;

	// Satisfaction table
	std::cout << "*********************************************************" << std::endl;
	std::cout << "               Customer Satisfaction Info                " << std::endl;
	std::cout << std::left << std::setw(18)
		<< "Average Score: " << std::fixed 
		<< std::setprecision(1) << getAverageScore() << std::endl;
	std::cout << std::left << std::setw(18)
		<< "Highest Score: " << std::fixed
		<< std::setprecision(1) << getHighestScore() << std::endl;
	std::cout << std::left << std::setw(18)
		<< "Lowest Score: " << std::fixed
		<< std::setprecision(1) << getLowestScore() << std::endl;
	std::cout << "List of all recored scores:" << std::endl;

	// Sort and print the scores
	sortScores();
	for (double i : this->scores) {
		std::cout << i << std::endl;
	}

	std::cout << "*********************************************************" << std::endl;
}
