#pragma once

#include <vector>
#include "Laser.h"

using namespace std;

class LaserList
{
private:
	vector<Laser> laserList;

public:
	LaserList();
	~LaserList();

	void addLaser(Point pos);
	void updateLaserList(int dir, int width, int height);

	void eraseLaser(Point pos);
	vector<Laser> getLaserList() { return laserList; }

};