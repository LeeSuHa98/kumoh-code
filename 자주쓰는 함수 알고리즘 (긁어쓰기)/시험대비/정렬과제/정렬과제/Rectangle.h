#pragma once
#include "std.h"

using namespace std;

class Rectangle
{
private:
	double width;
	double height;
public:
	Rectangle() {}
	Rectangle(double w, double h)
	{
		width = w;
		height = h;
	}
	double getArea() { return width*height; }

	friend ostream& operator<<(ostream& os, Rectangle& rec)
	{
		os << rec.getArea();

		return os;
	}
	friend bool operator<(Rectangle& rec1, Rectangle& rec2)
	{
		if (rec1.getArea() < rec2.getArea())
			return true;
		return false;
	}
	friend bool operator>(Rectangle& rec1, Rectangle& rec2)
	{
		if (rec1.getArea() > rec2.getArea())
			return true;
		return false;
	}
	friend bool operator<=(Rectangle& rec1, Rectangle& rec2)
	{
		if (rec1.getArea() <= rec2.getArea())
			return true;
		return false;
	}
	friend bool operator>=(Rectangle& rec1, Rectangle& rec2)
	{
		if (rec1.getArea() >= rec2.getArea())
			return true;
		return false;
	}
	friend bool operator==(Rectangle& rec1, Rectangle& rec2)
	{
		if (rec1.getArea() == rec2.getArea())
			return true;
		return false;
	}
};