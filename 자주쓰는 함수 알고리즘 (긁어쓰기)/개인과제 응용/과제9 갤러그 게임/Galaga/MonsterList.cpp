#include "MonsterList.h"

int MonsterList::allMove(int width, int height)
{
	vector<Monster>::iterator iter;
	bool isOut = false;
/*
	for (int i = 0; i < monsterList.size(); ++i)
		if (monsterList[i].galagaMove(width, height) == OUT_MONSTER)
			*/

	for (iter = monsterList.begin(); iter != monsterList.end(); )
		if ((*iter).galagaMove(width, height) == OUT_MONSTER)
		{	// 몬스터가 밖을 나가면
			isOut = true;
			iter = monsterList.erase(iter);
		}
		else
			iter++;

	if (isOut)
		return OUT_MONSTER;
	return CONTINUE;
}

void MonsterList::addMonster(int width, int numOfMonster)
{
	srand(time(NULL));

	const int MAX_SIZE = 1000;
	int arr[MAX_SIZE] = { 0, };

	for (int i = 0; i < numOfMonster; ++i)
	{
		int x = rand() % width;
		while (arr[x] != 0)
			x = rand() % width;
		monsterList.push_back(Monster(Point(x, 0), LEVEL1));
	}
}

//int MonsterList::updateMap(vector<vector<int>>& matrix, int width, int height)
//{
//	bool checkEnd = false;
//	for (int i = 0; i < monsterList.size(); ++i)
//	{
//		Point pos = monsterList[i].getPoint();
//		int x = pos.getX();
//		int y = pos.getY();
//		if (matrix[y][x] == EMPTY)		// 비어있을 경우
//			matrix[y][x] = MONSTER;			// Monster Update;
//		else if (matrix[y][x] == PLAYER)	// 플레이어와 충돌
//		{
//			matrix[y][x] = CRASH_PLAYER;
//			checkEnd = true;
//		}
//		else if (matrix[y][x] == LASER)		// 레이져와 충돌
//			matrix[y][x] = CRASH_MOB;
//	}
//
//	if (checkEnd == true)
//		return END;
//	return CONTINUE;
//}

void MonsterList::eraseMonster(Point pos)
{
	vector<Monster>::iterator iter;
	for (iter = monsterList.begin(); iter != monsterList.end();)
		if ((*iter).getPoint().isSame(pos))
			iter = monsterList.erase(iter);
		else
			iter++;
}
