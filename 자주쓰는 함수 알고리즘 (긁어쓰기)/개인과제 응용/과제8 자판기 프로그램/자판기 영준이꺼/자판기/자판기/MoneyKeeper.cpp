#include "MoneyKeeper.h"


MoneyKeeper::MoneyKeeper(void)
{
	total_money = 0;
}


MoneyKeeper::~MoneyKeeper(void)
{
}

void MoneyKeeper::increase_money(int index)
{
	if(index == 1)
		total_money += 1000;
	else if(index == 2)
		total_money += 500;
	else if(index == 3)
		total_money += 100;
	else if(index == 4)
		total_money += 50;
	else
	    cout << "������ �ٽ� �����Ͻÿ�. " << endl;
}

void MoneyKeeper::decrease_money(int money)
{
	total_money -= money;
}