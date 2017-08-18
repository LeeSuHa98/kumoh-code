#pragma once
#include "Baseball.h"
#include "Human.h"
#include "Bot.h"

class Player
{
private:
	int strike;
	int ball; 
public:
	Player()
	{
		strike = 0;
		ball = 0;
	}
	~Player() {}

	void ballMatch(Human& h, Bot& b);
	void botGameStart(Bot& b);
	void humanGameStart(Human& h);
};