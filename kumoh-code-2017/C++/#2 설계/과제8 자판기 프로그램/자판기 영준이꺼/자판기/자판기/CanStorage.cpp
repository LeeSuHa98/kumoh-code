#include "CanStorage.h"


CanStorage::CanStorage(void)
{
	canList = new Can[10];
	count = 0;
}


CanStorage::~CanStorage(void)
{
}


void CanStorage::insertCanList(int id,string name,int price,int quantity)
{
	Can c;
	c.id = id;
	c.name = name;
	c.price = price;
	c.stock_quantity = quantity;

	canList[count++] = c;
}

void CanStorage::updateAmount(int id)
{
	canList[id-1].stock_quantity--;
}