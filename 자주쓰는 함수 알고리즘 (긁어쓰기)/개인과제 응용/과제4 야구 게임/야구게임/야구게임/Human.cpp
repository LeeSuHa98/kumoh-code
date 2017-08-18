#include "Human.h"

void Human::humanSettingGame()
{
	while (1)
	{
		cout << " 첫번째 수 : " << endl;
		cin >> human_setting[0];

		cout << " 두번째 수 : " << endl;
		cin >> human_setting[1];

		cout << " 세번째 수 : " << endl;
		cin >> human_setting[2];

		if (human_setting[0] < 0 || human_setting[0] > 9) continue;
		{
			break;
		}
	}
}

void Human::humanDisplayGame()
{
	cout << " 플레이어가 설정한 숫자 " << human_setting[0] << " " << human_setting[1] << " " << human_setting[2] << endl;
}