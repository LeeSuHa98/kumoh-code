#pragma once
#include "BookList.h"
class IoHandler
{
public:
	IoHandler() {}
	~IoHandler() {}
	// operations for menu handling
	int getMenu();
	void putMenu();

	// operations for getting & putting object
	Book* getBook();

	// operations for getting or putting simple value
	int getInteger(string msg);
	string getString(string msg);
	void putString(string msg) { cout << msg.c_str() << endl; }
	void putNewLine() { cout << endl; }
};