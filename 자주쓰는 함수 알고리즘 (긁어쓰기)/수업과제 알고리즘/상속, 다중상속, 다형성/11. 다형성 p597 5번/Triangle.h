#pragma once
#include "TwoDimShape.h"

class Triangle : public TwoDimShape
{
public:
	Triangle() {}
	Triangle(double radius) : TwoDimShape(radius) {}
	~Triangle() {}

	void getArea()
	{
		cout << " ¸éÀû : " << 3.14 * radius * radius << endl;
	}
};

