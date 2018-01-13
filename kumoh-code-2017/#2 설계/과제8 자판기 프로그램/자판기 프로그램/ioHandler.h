#pragma once
#include "CanStorage.h"
#include "MoneyKeeper.h"

class ioHandler
{
public:
	ioHandler() {}
	~ioHandler() {}

	void putString(string msg) { cout << msg.c_str() << endl; }
	int getMenu();
	int getCoinMenu();
	int getSelectMenu();
	void displayMenu(CanStorage& c_list);

	int getInteger(string msg);
	string getString(string msg);

	void loadCanStorage(string filename, CanStorage& c_list);
};
