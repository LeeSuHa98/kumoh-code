#pragma once
#include "TwoDimShape.h"

class Ellipse : public TwoDimShape
{
public:
	Ellipse() {}
	Ellipse(double radius) : TwoDimShape(radius) {}
	~Ellipse() {}

	void getArea()
	{
		cout << " ���� : " << 3.14 * radius * radius << endl;
	}
};

