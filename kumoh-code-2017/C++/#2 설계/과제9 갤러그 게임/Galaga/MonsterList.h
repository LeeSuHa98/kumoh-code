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
	//int updateMap(vector<vector<int>>& matrix, int width, int height);	// ������: ���Ϳ� Laser�浹�� Laser�� ������

	void eraseMonster(Point pos);		// pos ��ġ�� �ִ� ���� ����
	vector<Monster> getMonsterList() { return monsterList; }
};