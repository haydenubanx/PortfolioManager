#pragma once
#include <iostream> 
#include <string> 
#include <cctype>
#include <cstdlib>




class Date 
{
	//Overloading of the << operator
	friend std::ostream& operator<<(std::ostream&, Date);

public:

	//Date constructor
	Date(int d = 0, int m = 0, int yyyy = 0) 
	{
		setDate(d, m, yyyy);
	}

	//Date Destructor
	~Date() {}

	//Sets the date to the input values
	void setDate(int  d, int m, int yyyy) 
	{
			day = d;
			month = m;
			year = yyyy;
	}

	//Returns the day value
	int getDay() const
	{
		return day;
	}

	//Returns the month value
	int getMonth() const
	{
		return month;
	}

	//Returns teh year value
	int getYear() const
	{
		return year;
	}

	//Private variables for day, month, and year
private:
	int day = 1;
	int month = 1;
	int year= 2001;
};

//Definition for overloading of date output: operator <<
inline std::ostream& operator<<(std::ostream& output, Date d) 
{
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}
