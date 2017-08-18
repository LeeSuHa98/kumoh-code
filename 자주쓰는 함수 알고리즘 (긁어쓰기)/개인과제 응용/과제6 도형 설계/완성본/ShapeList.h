#pragma once
#include "Shape.h"

class ShapeList : public Shape
{
private:
	Shape* shape_list[MAX_NUM];
	int count;
public:
	ShapeList() { count = 0; }
	~ShapeList() {}

	Shape* getShapeList(int index) { return shape_list[index]; }
	int getCount() { return count; }
	int plusCount() { return count++; }

	//int findRectangle(int width, int height); // Rectangle Ã£±â

	void insertShape(Shape* s);
	void updateShape(int index, Shape* s);
	void displayShape();
};

