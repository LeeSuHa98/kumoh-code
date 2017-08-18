#pragma once
#include "Date.h"

class Time
{
protected:
	int hour; // ½Ã
	int minute; // ºÐ
	int second; // ÃÊ
public:
	Time() {}
	Time(int hour, int minute, int second)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	~Time() {}

	void print();
};

