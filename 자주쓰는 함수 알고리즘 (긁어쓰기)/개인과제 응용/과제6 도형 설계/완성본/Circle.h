#pragma once
#include "Shape.h"
#include "ShapeList.h"

class Circle : public Shape
{
private:
	int radius; // 반지름
public:
	Circle() {}
	Circle(int centerX, int centerY, int radius) : Shape(centerX, centerY)
	{
		this->radius = radius;
	}
	~Circle() {}

	//int getRadius() { return radius; }

	/*int findCircle(ShapeList& s_list);*/
	Circle* registerCircle(ShapeList& s_list);
	void loadCircle(string fileName, ShapeList& s_list);
	void saveCircle(string fileName, ShapeList& s_list);
	//int insertShapeType(); // 도형의 종류 찾기
	//Shape* getCircle(int shape_type, ShapeList& s_list);

	void print();
	void calArea();
	void resize();
};

