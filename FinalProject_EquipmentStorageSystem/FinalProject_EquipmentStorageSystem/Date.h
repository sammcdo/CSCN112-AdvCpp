#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>

class Date
{
	friend std::ostream& operator<<(std::ostream& output, Date d);
	
public:
	Date(int d = 0, int m = 0, int yyyy = 0)
	{
		setDate(d, m, yyyy);
	}

	Date(const Date& old) {
		setDate(old.getDay(), old.getMonth(), old.getYear());
	}

	~Date() {}

	void setDate(int  d, int m, int yyyy)
	{
		day = d;
		month = m;
		year = yyyy;
	}

	int getDay() const { 
		return day;
	}
	int getMonth() const { 
		return month; 
	}
	int getYear() const { 
		return year; 
	}

private:
	int day;
	int month;
	int year;
};


inline std::ostream& operator<<(std::ostream& output, Date d)
{
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}