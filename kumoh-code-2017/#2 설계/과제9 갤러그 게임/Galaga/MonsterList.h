#pragma once

#include "Monster.h"
#include <vector>
#include <ctime>

class MonsterList
{
private:
	vector<Monster> monsterList;

public:
	MonsterList() {}
	~MonsterList() {}

	int allMove(int width, int height);
	void addMonster(int width, int numOfMonster);
	//int updateMap(vector<vector<int>>& matrix, int width, int height);	// 문제점: 몬스터와 Laser충돌시 Laser를 지울방법

	void eraseMonster(Point pos);		// pos 위치에 있는 몬스터 지움
	vector<Monster> getMonsterList() { return monsterList; }
};