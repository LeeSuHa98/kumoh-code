#pragma once
#include "Baseball.h"

class Bot
{
	int bot_setting[MAX_COUNT];
public:
	Bot() {}
	~Bot() {}

	int getBotSetting(int index) { return bot_setting[index]; }

	void botSettingGame();
	void botDisplayGame();
};