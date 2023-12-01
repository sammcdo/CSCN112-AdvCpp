// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

// Code courtesy of Dr. Melesa Poole

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Date.h"

Date::Date(int m, int d, int yyyy) {
	setDate(m, d, yyyy);
}

Date::~Date() {}

void Date::setDate(int m, int d, int yyyy) {
	month = m;
	day = d;
	year = yyyy;
}

std::ostream& operator<<(std::ostream& output, Date d) {
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}