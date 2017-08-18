#include "MapUpdator.h"

MapUpdator::MapUpdator(int width, int height) : width(width), height(height)
{
}

vector<vector<int>> MapUpdator::updataMap(LaserList& lasers, MonsterList& monsters, Player & player, bool& isEnded)
{
	vector<Laser> laserList = lasers.getLaserList();
	vector<Monster> monsterList = monsters.getMonsterList();
	
	vector<vector<int>> map = vector<vector<int>>(height, vector<int>(width, 0));

	Point pos = player.getPoint();
	int x = pos.getX();
	int y = pos.getY();

	map[y][x] = PLAYER;
	
	for (int i = 0; i < laserList.size(); ++i)
	{
		pos = laserList[i].getPoint();
		map[pos.getY()][pos.getX()] = LASER;
	}

	for (int j = 0; j < monsterList.size(); ++j)
	{
		pos = monsterList[j].getPoint();
		x = pos.getX();
		y = pos.getY();
		if (y - 1 >= 0 && map[y - 1][x] == LASER)
		{	// Ãæµ¹
			lasers.eraseLaser(Point(x, y - 1));
			monsters.eraseMonster(Point(x, y));

			map[y][x] = CRASH_MOB;
		}
		else if (map[y][x] == LASER)
		{
			lasers.eraseLaser(Point(x, y));
			monsters.eraseMonster(Point(x, y));

			map[y][x] = CRASH_MOB;
		}
		else if (map[y][x] == PLAYER)
		{
			map[y][x] = CRASH_PLAYER;
			isEnded = true;
		}

		else if (map[y][x] == EMPTY)
			map[y][x] = MONSTER;
	}
	return map;
}
