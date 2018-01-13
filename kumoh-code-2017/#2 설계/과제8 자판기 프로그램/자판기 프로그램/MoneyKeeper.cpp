#include "MoneyKeeper.h"

void MoneyKeeper::plusMoney(int index)
{
	if (index == 1)
	{
		money += 10;

		cout << " 투입금액 : " << money << endl;
	}
	else if (index == 2)
	{
		money += 50;

		cout << " 투입금액 : " << money << endl;
	}
	else if (index == 3)
	{
		money += 100;

		cout << " 투입금액 : " << money << endl;
	}
	else if (index == 4)
	{
		money += 500;

		cout << " 투입금액 : " << money << endl;
	}
	else
	{
		cout << " 동전을 다시 투입하시오. " << endl;
	}
}

void MoneyKeeper::minusMoney(int index)
{
	if (money == index)
	{
		money -= index;
		cout << " 물품을 구매하였습니다. " << endl;
		cout << " 현재 잔액 : " << money << endl;
	}
	else if (money >= index)
	{
		money -= index;
		cout << " 물품을 구매하였습니다. " << endl;
		cout << " 현재 잔액 : " << money << endl;
	}
}

int MoneyKeeper::compareMoney(int index)
{
	if (money < index)
	{
		cout << " 돈이 부족합니다. 동전을 다시 넣어주세요." << endl;
		cout << " 현재 잔액 : " << money << endl;

		return lACK_MONEY;
	}
	return ENOUGH_MONEY;
}

void MoneyKeeper::returnMoney()
{
	cout << " 잔돈 " << money << "원이 반환되었습니다 " << endl;

	money = 0;

	cout << " 현재 잔액 : " << money << endl;
}