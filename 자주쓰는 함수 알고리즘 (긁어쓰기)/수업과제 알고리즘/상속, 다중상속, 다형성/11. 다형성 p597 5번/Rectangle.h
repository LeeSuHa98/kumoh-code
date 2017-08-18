#pragma once
#include "TwoDimShape.h"

class Rectangle : public TwoDimShape
{
public:
	Rectangle() {}
	Rectangle(double radius) : TwoDimShape(radius) {}
	~Rectangle() {}

	void getArea()
	{
		cout << " ���� : " << 3.14 * radius * radius << endl;
	}
};

