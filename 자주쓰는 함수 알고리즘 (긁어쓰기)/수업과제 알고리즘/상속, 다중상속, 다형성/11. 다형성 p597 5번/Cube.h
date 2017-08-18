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
		cout << " Ã¼Àû : " << radius / 3 << endl;
	}
};

