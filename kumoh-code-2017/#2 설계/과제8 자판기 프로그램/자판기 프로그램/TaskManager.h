#pragma once
#include "CanStorage.h"
#include "MoneyKeeper.h"
#include "ioHandler.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	// ���� ����
	void insertCoin(MoneyKeeper& mk);
	// ��ǰ ����
	void selectMenu(MoneyKeeper& mk, CanStorage& c_list);
	// �ܵ� ��ȯ
	void returnCoin(MoneyKeeper& mk);
};