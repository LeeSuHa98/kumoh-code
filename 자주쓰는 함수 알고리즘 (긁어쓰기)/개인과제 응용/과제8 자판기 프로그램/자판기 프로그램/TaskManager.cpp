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

	Can c = c_list.getCanList(menu - 1); // 메뉴의 선택번호와 배열의 번호를 조정
	// 캔의 재고를 확인할 때 돈의 경우를 보고 재고를 삭감
	c_list.updateCanStorage(mk.compareMoney(c.getPrice()), menu);
	// 물품을 구매할 수 있으면 돈 삭감
	mk.minusMoney(c.getPrice());

	ioh.displayMenu(c_list);
}

void TaskManager::returnCoin(MoneyKeeper& mk)
{
	mk.returnMoney();
}