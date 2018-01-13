#pragma once
#include "Shape.h"

class Circle : public Shape
{
private:
	int radius; // ¹ÝÁö¸§
public:
	Circle() {}
	Circle(int centerX, int centerY, int radius) : Shape(centerX, centerY)
	{
		this->radius;
	}
	~Circle() {}

	void print();
	void calArea();
	void resize(int radius);
};

