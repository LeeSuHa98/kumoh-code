#pragma once
#include <iostream>

using namespace std;

class Shape
{
protected:
	int centerX;
	int centerY;
public:
	Shape() {}
	Shape(int centerX, int centerY)
	{
		this->centerX = centerX;
		this->centerY = centerY;
	}
	~Shape() {}

	virtual void print();
	virtual void calArea();
};

