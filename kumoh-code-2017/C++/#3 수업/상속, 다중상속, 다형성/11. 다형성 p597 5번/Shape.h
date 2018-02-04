#pragma once
#include <iostream>

using namespace std;

class Shape
{
protected:
	double radius;
public:
	Shape() {}
	Shape(double radius)
	{
		this->radius = radius;
	}
	~Shape() {}

	virtual void getArea() {}
};

