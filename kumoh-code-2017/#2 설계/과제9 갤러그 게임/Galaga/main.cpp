#include "LaserList.h"
#include "MonsterList.h"
#include "Player.h"
#include "MapUpdator.h"
#include "IOHandler.h"

#include <conio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	int height, width;
	height = 30;
	width = 50;
	LaserList lasers;
	MonsterList monsters;
	Player player(Point(width / 2, height - 1));
	MapUpdator mapUpdator(width, height);

	vector<vector<int>> before = vector<vector<int>>(height, vector<int>(width, 0));
	vector<vector<int>> map;

	IOHandler ioh;
	Point pos;
	bool flag = true;
	char choice;
	int time = 0;

	monsters.addMonster(width, 10);
	ioh.printMap(before);
	while (1)
	{
		system("cls");
		map = mapUpdator.updataMap(lasers, monsters, player, flag);
		ioh.printMap(map);
		before = map;

		if (_kbhit())
		{
			choice = _getch();
			pos = player.getPoint();

			switch (choice)
			{
			case ' ':
				pos.setY(pos.getY() - 1);
				lasers.addLaser(pos);
				break;

			case 'k':
				player.move(LEFT);
				break;

			case ';':
				player.move(RIGHT);
				break;

			case 'o':
				player.move(UP);
				break;

			case 'l':
				if (pos.getY() + 1 < height)
					player.move(DOWN);
				break;
			}
		}

		Sleep(10);
		time++;
		lasers.updateLaserList(UP, width, height);
		
		if (time % 10 == 0)
			monsters.allMove(width, height);
	}
	return 0;
}