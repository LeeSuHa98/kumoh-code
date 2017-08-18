#include "CanStorage.h"
#include "MoneyKeeper.h"
#include "ioHandler.h"
#include "TaskManager.h"

int main()
{
	CanStorage c_list;
	MoneyKeeper mk;
	ioHandler ioh;
	TaskManager tm;

	// load from file.
	ioh.loadCanStorage("canlist.txt", c_list);

	while (1)
	{
		int menu = ioh.getMenu();
		if (menu == EXIT) break; // 프로그램 종료

		switch (menu)
		{
		case COIN_DEPOSIT:
			// 동전투입
			tm.insertCoin(mk);
			break;
		case ITEM_SELECTION:
			// 상품선택
			tm.selectMenu(mk, c_list);
			break;
		case CHANGE_RETURN:
			// 잔돈반환
			tm.returnCoin(mk);
			break;
		case EXIT:
			// 프로그램 종료
			return 0;
		}
	}
}