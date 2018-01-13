#pragma once
#include "Shape.h"

class TwoDimShape : public Shape
{
public:
	TwoDimShape() {}
	TwoDimShape(double radius) : Shape(radius) {}
	~TwoDimShape() {}

	void getArea()
	{
		cout << " ¸éÀû : " << 3.14 * radius * radius << endl;
	}
};

