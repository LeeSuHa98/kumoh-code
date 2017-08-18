#include "Player.h"
#include "Bot.h"
#include "Human.h"
#include "Player.h"

int main()
{
	Bot b;
	Human h;

	while (true)
	{
		Player p;

		cout << "---------- 야구게임 ----------" << endl;
		cout << "------- 1. bot setting -------" << endl;
		cout << "------- 2. player setting ----" << endl;
		cout << "------- 3. 프로그램 종료 -----" << endl;

		int select;
		cin >> select;

		switch (select)
		{
		case 1:
			// bot game setting
			p.botGameStart(b);
			break;
		case 2:
			// player game setting
			p.humanGameStart(h);
			p.ballMatch(h, b);
			break;
		case 3:
			cout << " 프로그램을 종료합니다 " << endl;
			exit(1);
			break;
		default:
			// 예외처리
			cout << " 잘못 입력하셨습니다 " << endl;
			return 0;
		}
	}
}