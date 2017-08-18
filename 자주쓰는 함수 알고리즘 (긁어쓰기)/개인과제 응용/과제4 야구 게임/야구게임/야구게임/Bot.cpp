#include "Bot.h"

void Bot::botSettingGame()
{
	while (true)
	{
		bot_setting[0] = rand() % 9 + 1;

		bot_setting[1] = rand() % 9 + 1;
		if (bot_setting[1] == bot_setting[0]) continue;

		bot_setting[2] = rand() % 9 + 1;
		if (bot_setting[2] == bot_setting[0] || bot_setting[2] == bot_setting[1]) continue;

		if (bot_setting[0] != bot_setting[1] && bot_setting[0] != bot_setting[2] && bot_setting[1] != bot_setting[2])
			break;
	}
}

void Bot::botDisplayGame()
{
	cout << " 봇이 설정한 숫자 " << bot_setting[0] << " " << bot_setting[1] << " " << bot_setting[2] << endl;
}