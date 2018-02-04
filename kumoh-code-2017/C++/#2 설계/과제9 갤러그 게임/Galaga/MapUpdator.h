#pragma once

#include "LaserList.h"
#include "MonsterList.h"
#include "Player.h"

#include <vector>

class MapUpdator
{
private:
	int width, height;

public:
	MapUpdator(int width, int height);

	vector<vector<int>> updataMap(LaserList& laser, MonsterList& monster, Player& player, bool& isEnded);
	bool isBoundary(int x, int y) { return (x < 0 || x >= width || y < 0 || y >= height); }
};