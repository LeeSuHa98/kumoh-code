#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date
{
protected:
	int year; // ³â
	int month; // ¿ù
	int date; // ÀÏ
	
public:
	Date() {}
	Date(int year, int month, int date)
	{
		this->year = year;
		this->month = month;
		this->date = date;
	}
	~Date() {}

	void print();
};

