#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

class Galaga
{
protected:
	Point pos;


public:
	Galaga() {}
	Galaga(Point pos) : pos(pos) {}

	~Galaga() {}
	Point getPoint() { return pos; }
};

