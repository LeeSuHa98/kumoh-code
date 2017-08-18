#pragma once
#include "ThreeDimShape.h"

class Cylinder : public ThreeDimShape
{
public:
	Cylinder() {}
	Cylinder(double radius) : ThreeDimShape(radius) {}
	~Cylinder() {}

	void getArea()
	{
		cout << " ü�� : " << radius / 3 << endl;
	}
};

