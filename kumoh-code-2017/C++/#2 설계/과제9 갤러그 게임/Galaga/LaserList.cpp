#include "LaserList.h"

LaserList::LaserList()
{
}

LaserList::~LaserList()
{
}

void LaserList::addLaser(Point pos)
{
	laserList.push_back(Laser(pos));
}

void LaserList::updateLaserList(int dir, int width, int height)
{
	vector<Laser>::iterator iter;

	for (iter = laserList.begin(); iter != laserList.end();)
	{
		bool result = (*iter).laserMove(dir, width, height);
		if (result)
			iter++;
		else
			iter = laserList.erase(iter);
	}
}

void LaserList::eraseLaser(Point pos)
{
	vector<Laser>::iterator iter;

	for (iter = laserList.begin(); iter != laserList.end();)
		if ((*iter).getPoint().isSame(pos))
			iter = laserList.erase(iter);
		else
			iter++;
}
