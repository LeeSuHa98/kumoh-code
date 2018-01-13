#pragma once
#include "ThreeDimShape.h"

class Cube : public ThreeDimShape
{
public:
	Cube() {}
	Cube(double radius) : ThreeDimShape(radius) {}
	~Cube() {}

	void getArea()
	{
		cout << " ü�� : " << radius / 3 << endl;
	}
};

