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
		if (menu == EXIT) break; // ���α׷� ����

		switch (menu)
		{
		case COIN_DEPOSIT:
			// ��������
			tm.insertCoin(mk);
			break;
		case ITEM_SELECTION:
			// ��ǰ����
			tm.selectMenu(mk, c_list);
			break;
		case CHANGE_RETURN:
			// �ܵ���ȯ
			tm.returnCoin(mk);
			break;
		case EXIT:
			// ���α׷� ����
			return 0;
		}
	}
}