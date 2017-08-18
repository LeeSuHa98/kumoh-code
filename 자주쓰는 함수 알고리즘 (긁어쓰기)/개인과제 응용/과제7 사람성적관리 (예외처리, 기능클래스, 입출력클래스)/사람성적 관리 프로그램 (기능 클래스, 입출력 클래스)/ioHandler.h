#pragma once
#include "PersonList.h"

class ioHandler
{
public:
	int getMenu();

	Person getStudent(string name, PersonList& p_list);
	void putStudent(Person s);

	string getString(string msg);
	int getInteger(string msg);
	double getDouble(string msg);

	void putString(string msg) { cout << msg.c_str() << endl; }
};