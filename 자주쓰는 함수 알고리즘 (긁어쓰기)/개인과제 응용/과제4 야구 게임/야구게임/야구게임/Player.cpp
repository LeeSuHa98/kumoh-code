#include "Player.h"

void Player::ballMatch(Human& h, Bot& b)
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (b.getBotSetting(i) == h.getHumanSetting(j))
			{
				if (i == j) { (strike)++; }

				else { (ball)++; }
			}
		}
	}

	cout << " strike : " << strike << " ball : " << ball << endl;
}

void Player::botGameStart(Bot &b)
{
	cout << " The bot game is setting " << endl;

	b.botSettingGame();
	b.botDisplayGame();
}

void Player::humanGameStart(Human& h)
{
	cout << " The player game is setting " << endl;

	h.humanSettingGame();
	h.humanDisplayGame();
}