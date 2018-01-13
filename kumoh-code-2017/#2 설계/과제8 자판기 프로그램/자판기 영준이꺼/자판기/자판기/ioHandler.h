#pragma once
#include <fstream>
#include <string>

#include "MoneyKeeper.h"
#include "CanStorage.h"

class ioHandler
{
public:
	ioHandler(void);
	~ioHandler(void);

	void loadCanList(string msg,CanStorage& cs);

	int getMenu();
	int getInteger(string msg);
	void printQuantity(CanStorage cs);
	void printRemainedCoin(MoneyKeeper mk);
};

