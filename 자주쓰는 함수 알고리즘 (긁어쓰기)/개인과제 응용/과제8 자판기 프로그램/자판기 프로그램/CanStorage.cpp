#include "CanStorage.h"

void CanStorage::insertCanStorage(Can c)
{
	can_list[count] = c;
}

void CanStorage::updateCanStorage(int money, int index)
{
	if (money == 1)
	{
		can_list[index - 1].minusQuantity(); // ���谨
	}
	else if (money == -1)
	{
		can_list[index - 1].getQuantity(); // �����
	}
}