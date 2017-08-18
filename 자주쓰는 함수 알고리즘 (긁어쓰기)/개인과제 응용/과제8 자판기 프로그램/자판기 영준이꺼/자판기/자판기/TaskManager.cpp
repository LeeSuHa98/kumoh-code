#include "TaskManager.h"


TaskManager::TaskManager(void)
{
}


TaskManager::~TaskManager(void)
{
}

void TaskManager::insertCoin(MoneyKeeper& mk)
{
	int select;
	cout << "[1] 1000원 [2] 500원 [3] 100원 [4] 50원 " << endl;
	cout << "투입할 동전선택-> ";
	cin >> select;
	mk.increase_money(select);

	cout << "잔액 -> " << mk.getMoney() << endl;
}

void TaskManager::selectItem(CanStorage& cs,MoneyKeeper& mk)
{
	ioHandler ioh;
	ioh.printQuantity(cs);
	int select = ioh.getInteger("[1] 콜라 [2] 사이다 [3] 오란씨 [4] 코코포도 [5] 레쓰비 [6] 쭈니입술");
	if(cs.getCanList(select-1).price > mk.getMoney())
		cout << "잔액이 부족합니다." << endl;
	else if(cs.getCanList(select-1).stock_quantity == 0)
		cout << "재고수량이 없습니다." << endl;
	else
	{
		// 상품을 선택하면 
		cs.updateAmount(select);  // 재고수량 업데이트  
		mk.decrease_money(cs.getCanList(select-1).price);  // 잔액 감소
		ioh.printRemainedCoin(mk);
	}
}

void TaskManager::changeReturn(MoneyKeeper& mk)
{
	cout << "---------------------------------------------------------" << endl;
	cout << "거스름돈은 " << mk.getMoney() << "원 입니다. " << endl;
	cout << "---------------------------------------------------------" << endl;
	mk.changeReturn();
}