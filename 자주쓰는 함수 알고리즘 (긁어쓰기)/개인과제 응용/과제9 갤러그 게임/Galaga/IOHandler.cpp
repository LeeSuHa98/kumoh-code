#include "IOHandler.h"

void IOHandler::printMap(vector<vector<int>> map)
{
	for (int i = 0; i < map[0].size() + 2; ++i)
		cout << '-';
	cout << endl;

	for (int i = 0; i < map.size(); ++i)
	{
		//cout << ' '
		for (int j = 0; j < map[0].size(); ++j)
		{
			switch (map[i][j])
			{
			case EMPTY:
				cout << " ";
				break;

			case MONSTER:
				cout << "*";
				break;

			case PLAYER:
				cout << "^";
				break;

			case LASER:
				cout << "l";
				break;

			case CRASH_MOB:
				cout << "@";
				break;

			case CRASH_PLAYER:
				cout << "#";
				break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < map[0].size() + 2; ++i)
		cout << '-';
	cout << endl;
}

void IOHandler::printMap(vector<vector<int>> before, vector<vector<int>> after)
{
	for (int i = 0; i < after.size(); ++i)
	{
		for (int j = 0; j < after[0].size(); ++j)
		{
			if (before[i][j] != after[i][j])
			{
				COORD pos = { i, j };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				char p;
				switch (after[i][j])
				{
				case EMPTY:
					p = ' ';
					break;

				case MONSTER:
					p = '*';
					break;

				case PLAYER:
					p = '^';
					break;

				case LASER:
					p = 'l';
					break;

				case CRASH_MOB:
					p = '@';
					break;

				case CRASH_PLAYER:
					p = '#';
					break;
				}// end switch
				printf("%c", p);
			}	// end if
		}
	}
}
