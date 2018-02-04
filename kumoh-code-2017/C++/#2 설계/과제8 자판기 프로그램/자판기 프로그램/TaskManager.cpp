#include "TaskManager.h"

void TaskManager::insertCoin(MoneyKeeper& mk)
{
	ioHandler ioh;

	int menu = ioh.getCoinMenu();

	mk.plusMoney(menu);
}

void TaskManager::selectMenu(MoneyKeeper& mk, CanStorage& c_list)
{
	ioHandler ioh;

	int menu = ioh.getSelectMenu();

	Can c = c_list.getCanList(menu - 1); // �޴��� ���ù�ȣ�� �迭�� ��ȣ�� ����
	// ĵ�� ��� Ȯ���� �� ���� ��츦 ���� ��� �谨
	c_list.updateCanStorage(mk.compareMoney(c.getPrice()), menu);
	// ��ǰ�� ������ �� ������ �� �谨
	mk.minusMoney(c.getPrice());

	ioh.displayMenu(c_list);
}

void TaskManager::returnCoin(MoneyKeeper& mk)
{
	mk.returnMoney();
}