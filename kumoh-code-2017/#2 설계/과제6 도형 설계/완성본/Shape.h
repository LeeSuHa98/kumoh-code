#pragma once
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_NUM = 10;

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

	virtual void print() {}
	virtual void calArea() {}
};

