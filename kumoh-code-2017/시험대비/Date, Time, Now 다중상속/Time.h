#pragma once
#include "Date.h"

class Time
{
protected:
	int hour; // ��
	int minute; // ��
	int second; // ��
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

