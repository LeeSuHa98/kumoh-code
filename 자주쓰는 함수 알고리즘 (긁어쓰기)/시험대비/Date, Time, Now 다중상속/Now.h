#pragma once
#include "Date.h"
#include "Time.h"

class Now : public Date, Time
{
private:
	int microsec;
	bool mode;
public:
	Now() {}
	Now(int year, int month, int date, int hour, int minute, int second, int microsec) : Date(year, month, date), Time(hour, minute, second)
	{
		this->microsec = microsec;
	}
	Now(int year, int month, int date, int hour, int minute, int second, int microsec, bool mode) : Date(year,month,date), Time(hour,minute,second)
	{
		this->microsec = microsec;
		this->mode = mode;
	}
	~Now() {}

	void print();
};

