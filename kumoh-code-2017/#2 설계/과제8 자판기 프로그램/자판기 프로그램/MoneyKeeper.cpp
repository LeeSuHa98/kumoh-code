#include "MoneyKeeper.h"

void MoneyKeeper::plusMoney(int index)
{
	if (index == 1)
	{
		money += 10;

		cout << " ���Աݾ� : " << money << endl;
	}
	else if (index == 2)
	{
		money += 50;

		cout << " ���Աݾ� : " << money << endl;
	}
	else if (index == 3)
	{
		money += 100;

		cout << " ���Աݾ� : " << money << endl;
	}
	else if (index == 4)
	{
		money += 500;

		cout << " ���Աݾ� : " << money << endl;
	}
	else
	{
		cout << " ������ �ٽ� �����Ͻÿ�. " << endl;
	}
}

void MoneyKeeper::minusMoney(int index)
{
	if (money == index)
	{
		money -= index;
		cout << " ��ǰ�� �����Ͽ����ϴ�. " << endl;
		cout << " ���� �ܾ� : " << money << endl;
	}
	else if (money >= index)
	{
		money -= index;
		cout << " ��ǰ�� �����Ͽ����ϴ�. " << endl;
		cout << " ���� �ܾ� : " << money << endl;
	}
}

int MoneyKeeper::compareMoney(int index)
{
	if (money < index)
	{
		cout << " ���� �����մϴ�. ������ �ٽ� �־��ּ���." << endl;
		cout << " ���� �ܾ� : " << money << endl;

		return lACK_MONEY;
	}
	return ENOUGH_MONEY;
}

void MoneyKeeper::returnMoney()
{
	cout << " �ܵ� " << money << "���� ��ȯ�Ǿ����ϴ� " << endl;

	money = 0;

	cout << " ���� �ܾ� : " << money << endl;
}