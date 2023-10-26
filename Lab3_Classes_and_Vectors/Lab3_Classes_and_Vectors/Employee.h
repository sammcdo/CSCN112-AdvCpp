#pragma once

#include <iostream>
#include <vector>

class Employee {
public:
	/*
	* Construct an employee
	* Defaults name, city, and id to empty strings
	*/
	Employee(std::string name="", std::string city="", std::string id="");
	/*
	* Destruct the employee
	*/
	~Employee();

	/*
	* Get the name of the employee
	* Return
	* The name of the employee
	*/
	std::string getName() const;
	/*
	* Set the name of the employee
	* Parameters
	* name - The new name of the employee
	*/
	void setName(std::string name);

	/*
	* Get the employee's city
	* Return
	* The employee's city
	*/
	std::string getCity() const;
	/*
	* Set the employee's city
	* Parameters
	* city - The new city
	*/
	void setCity(std::string city);

	/*
	* Get the ID of the employee
	* Return
	* The ID of the employee
	*/
	std::string getID() const;
	/*
	* Set the employee ID
	* Parameters
	* id - The new ID
	*/
	void setID(std::string id);
	
	/*
	* Get the satisfaction scores list
	* Return
	* The satisfaction scores
	*/
	std::vector<double> getScores() const;

	/*
	* Add a satisfaction score to the list.
	* Output whether the input was valid (1-5)
	* Parameters
	* score - The score to add
	* Return
	* Whether the score was valid and saved - True if it was saved, false if it was not
	*/
	bool addScore(double score);

	/*
	* Sort the satisfaction scores list inplace
	*/
	void sortScores();

	/*
	* Get the average satisfaction score.
	* Return
	* The average score
	*/
	double getAverageScore() const;

	/*
	* Get the lowest satisfaction score
	* Return
	* The lowest satisfaction score
	*/
	double getLowestScore() const;
	/*
	* Get the highest satisfaction score.
	* Return
	* The highest score.
	*/
	double getHighestScore() const;

	/*
	* Get the number of scores.
	* Return
	* The number of scores.
	*/
	int getNumberOfScores() const;

	/*
	* Print a table of employee information.
	* This includes name, city, and id.
	* It also shows the satisfaction scores and
	* high/low/average score information.
	*
	* This function will sort the scores before output.
	*/
	void printEmployeeInfo();

private:
	std::string name;
	std::string city;
	std::string id;

	std::vector<double> scores;
};
