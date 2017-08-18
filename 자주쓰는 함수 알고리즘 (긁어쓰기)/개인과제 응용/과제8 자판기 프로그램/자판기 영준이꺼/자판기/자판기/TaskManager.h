#pragma once
#include "ioHandler.h"

class TaskManager
{
public:
	TaskManager(void);
	~TaskManager(void);

	void insertCoin(MoneyKeeper& mk);
	void selectItem(CanStorage& cs,MoneyKeeper& mk);
	void changeReturn(MoneyKeeper& mk);
};

