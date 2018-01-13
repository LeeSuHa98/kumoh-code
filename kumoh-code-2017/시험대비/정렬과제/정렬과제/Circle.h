#pragma once
#include "std.h"
const double PI = 3.1415;

class Circle
{
private:
	double radius;

public:
	Circle() {}
	Circle(double r)
	{
		radius = r;
	}

	double getArea() { return radius*radius*PI; }

	friend ostream& operator<<(ostream& os, Circle& cr)
	{
		os << cr.getArea();

		return os;
	}
	friend bool operator<(Circle& cr1, Circle& cr2)
	{
		if (cr1.getArea() < cr2.getArea())
			return true;
		return false;
	}
	friend bool operator>(Circle& cr1, Circle& cr2)
	{
		if (cr1.getArea() > cr2.getArea())
			return true;
		return false;
	}
	friend bool operator<=(Circle& cr1, Circle& cr2)
	{
		if (cr1.getArea() <= cr2.getArea())
			return true;
		return false;
	}
	friend bool operator>=(Circle& cr1, Circle& cr2)
	{
		if (cr1.getArea() >= cr2.getArea())
			return true;
		return false;
	}
	friend bool operator==(Circle& cr1, Circle& cr2)
	{
		if (cr1.getArea() == cr2.getArea())
			return true;
		return false;
	}
};