#include "Laser.h"

Laser::Laser(Point pos) : pos(pos)
{
}

Laser::Laser()
{
}

Laser::~Laser()
{
}

bool Laser::laserMove(int dir, int width, int height)
{
	int x, y;
	x = pos.getX() + dx[dir];
	y = pos.getY() + dy[dir];

	if (x < 0 || x >= width || y < 0 || y >= height)
		return false;

	pos.pointMove(dir);
	return true;
}

