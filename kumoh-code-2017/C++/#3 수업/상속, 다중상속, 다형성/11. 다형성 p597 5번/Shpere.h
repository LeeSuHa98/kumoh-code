#pragma once
#include "ThreeDimShape.h"

class Shpere : public ThreeDimShape
{
public:
	Shpere() {}
	Shpere(double radius) : ThreeDimShape(radius) {}
	~Shpere() {}

	void getArea()
	{
		cout << " Ã¼Àû : " << radius / 3 << endl;
	}
};

