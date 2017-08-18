#include "ioHandler.h"
#include "TaskManager.h"

enum {COIN_DEPOSIT = 1 , ITEM_SELECTION , CHANGE_RETURN , EXIT};  // 열거형 enum -> 차례대로 1,2,3,4 로 저장됨

int main()
{
	ioHandler ioh;
	TaskManager tm;
	MoneyKeeper mk;
	CanStorage cs;
	ioh.loadCanList("CanList.dat",cs);

	while(1)
	{
		system("cls");
		int menu = ioh.getMenu();
		switch(menu)
		{
		case COIN_DEPOSIT:
			tm.insertCoin(mk);
			break;
		case ITEM_SELECTION:
			tm.selectItem(cs,mk);
			break;
		case CHANGE_RETURN:
			tm.changeReturn(mk);
			break;
		case EXIT:
			return 0;
		}
		system("pause");
	}
}