#pragma once

#include "Point.h"

class Laser
{
private:
	Point pos;
	int dir;

public:
	Laser(Point pos);
	Laser();
	~Laser();

	bool laserMove(int dir, int width, int height);
	Point getPoint() { return pos; }
};