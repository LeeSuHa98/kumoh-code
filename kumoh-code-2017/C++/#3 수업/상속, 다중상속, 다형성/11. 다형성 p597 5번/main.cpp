#include "Shape.h"
#include "TwoDimShape.h"
#include "ThreeDimShape.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Shpere.h"
#include "Cube.h"
#include "Cylinder.h"

int main()
{

	Shape* arr[6];
	arr[0] = new Ellipse(3);
	arr[1] = new Rectangle(6);
	arr[2] = new Triangle(9);
	arr[3] = new Shpere(12);
	arr[4] = new Cube(15);
	arr[5] = new Cylinder(18);

	for (int i = 0; i < 6; i++)
	{
		arr[i]->getArea();
	}

	return 0;
}
