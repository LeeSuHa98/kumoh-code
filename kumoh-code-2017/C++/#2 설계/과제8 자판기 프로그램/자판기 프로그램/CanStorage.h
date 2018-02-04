#pragma once
#include "MoneyKeeper.h"

class CanStorage
{
private:
	Can can_list[MAX_CAN];
	int count;
public:
	CanStorage()
	{
		count = 0;
	}
	~CanStorage() {}

	Can getCanList(int index) { return can_list[index]; }

	int getCount() { return count; }
	void plusCount() { count++; }
	void minusCount() { count--; }

	void insertCanStorage(Can c);
	void updateCanStorage(int money, int index);
};