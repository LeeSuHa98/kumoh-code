#pragma once
#include "Shape.h"

class ThreeDimShape : public Shape
{
public:
	ThreeDimShape() {}
	ThreeDimShape(double radius) : Shape(radius) {}
	~ThreeDimShape() {}
};

