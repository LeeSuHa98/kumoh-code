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
	cout << "[1] 1000�� [2] 500�� [3] 100�� [4] 50�� " << endl;
	cout << "������ ��������-> ";
	cin >> select;
	mk.increase_money(select);

	cout << "�ܾ� -> " << mk.getMoney() << endl;
}

void TaskManager::selectItem(CanStorage& cs,MoneyKeeper& mk)
{
	ioHandler ioh;
	ioh.printQuantity(cs);
	int select = ioh.getInteger("[1] �ݶ� [2] ���̴� [3] ������ [4] �������� [5] ������ [6] �޴��Լ�");
	if(cs.getCanList(select-1).price > mk.getMoney())
		cout << "�ܾ��� �����մϴ�." << endl;
	else if(cs.getCanList(select-1).stock_quantity == 0)
		cout << "�������� �����ϴ�." << endl;
	else
	{
		// ��ǰ�� �����ϸ� 
		cs.updateAmount(select);  // ������ ������Ʈ  
		mk.decrease_money(cs.getCanList(select-1).price);  // �ܾ� ����
		ioh.printRemainedCoin(mk);
	}
}

void TaskManager::changeReturn(MoneyKeeper& mk)
{
	cout << "---------------------------------------------------------" << endl;
	cout << "�Ž������� " << mk.getMoney() << "�� �Դϴ�. " << endl;
	cout << "---------------------------------------------------------" << endl;
	mk.changeReturn();
}