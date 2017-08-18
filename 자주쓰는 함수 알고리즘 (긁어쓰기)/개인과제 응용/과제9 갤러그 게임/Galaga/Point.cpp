#include "Point.h"

Point::Point(int x, int y) : x(x), y(y)
{
}

Point::Point()
{
}

Point::~Point()
{
}

bool Point::isSame(Point pos)
{
	return (pos.x == x && pos.y == y);
}

void Point::pointMove(int dir)
{
	x += dx[dir];
	y += dy[dir];
}
