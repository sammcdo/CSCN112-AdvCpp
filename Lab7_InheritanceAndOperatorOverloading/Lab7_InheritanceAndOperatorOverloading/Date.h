// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

// Code courtesy of Dr. Melesa Poole

#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>

class Date {
	friend std::ostream& operator<<(std::ostream&, Date);

public:
	Date(int m = 0, int d = 0, int yyyy = 0);

	~Date();

	void setDate(int m, int d, int yyyy);

private:
	int month;;
	int day;
	int year;
};
