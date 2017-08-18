#pragma once
#include "Shape.h"
#include "ShapeList.h"

class Rectangle : public Shape
{
private:
	int width; // 너비
	int height; // 높이
public:
	Rectangle() {}
	Rectangle(int centerX, int centerY, int width, int height) : Shape(centerX,centerY)
	{
		this->width = width;
		this->height = height;
	}
	~Rectangle() {}

	//int getWidth() { return width; }
	//int getHeight() { return height; }
	
	//int findRectangle(ShapeList& s_list);
	Rectangle* registerRectangle(ShapeList& s_list);
	void loadRectangle(string fileName, ShapeList& s_list);
	void saveRectangle(string fileName, ShapeList& s_list);
	//int insertShapeType(); // 도형의 종류 찾기
	//Shape* getRectangle(int shape_type, ShapeList& s_list);

	void print();
	void calArea();
	void resize();
};

