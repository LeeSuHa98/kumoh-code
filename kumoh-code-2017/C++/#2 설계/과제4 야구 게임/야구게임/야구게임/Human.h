#pragma once
#include "Baseball.h"

class Human
{
	int human_setting[MAX_COUNT];
public:
	Human() {}
	~Human() {}

	int getHumanSetting(int index) { return human_setting[index]; }

	void humanSettingGame();
	void humanDisplayGame();
};