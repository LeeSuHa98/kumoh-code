#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	int height; // 높이
	int width; // 너비
public:
	Rectangle() {}
	Rectangle(int centerX, int centerY, int height, int width) : Shape(centerX,centerY)
	{
		this->height = height;
		this->width = width;
	}
	~Rectangle() {}

	void print();
	void calArea();
	void resize(int width, int height);
};

