#include "Human.h"

void Human::humanSettingGame()
{
	while (1)
	{
		cout << " ù��° �� : " << endl;
		cin >> human_setting[0];

		cout << " �ι�° �� : " << endl;
		cin >> human_setting[1];

		cout << " ����° �� : " << endl;
		cin >> human_setting[2];

		if (human_setting[0] < 0 || human_setting[0] > 9) continue;
		{
			break;
		}
	}
}

void Human::humanDisplayGame()
{
	cout << " �÷��̾ ������ ���� " << human_setting[0] << " " << human_setting[1] << " " << human_setting[2] << endl;
}