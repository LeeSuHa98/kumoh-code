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

		cout << "---------- �߱����� ----------" << endl;
		cout << "------- 1. bot setting -------" << endl;
		cout << "------- 2. player setting ----" << endl;
		cout << "------- 3. ���α׷� ���� -----" << endl;

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
			cout << " ���α׷��� �����մϴ� " << endl;
			exit(1);
			break;
		default:
			// ����ó��
			cout << " �߸� �Է��ϼ̽��ϴ� " << endl;
			return 0;
		}
	}
}