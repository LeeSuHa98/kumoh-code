#pragma once
#include <iostream>

using namespace std;

class Vector
{
private:
	double x, y;
public:
	Vector() {}
	Vector(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	~Vector() {}

	friend Vector operator+(const Vector& v1, const Vector& v2);

	void display()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};

