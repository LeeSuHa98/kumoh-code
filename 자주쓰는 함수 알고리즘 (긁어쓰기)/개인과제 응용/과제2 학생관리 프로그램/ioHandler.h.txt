#pragma once
#include "TaskManager.h"

class ioHandler
{
public:
	int getMenu();

	Student getStudent();
	void putStudent(Student s);

	string getString(string msg);
	int getInteger(string msg);

	void putString(string msg) { cout << msg.c_str() << endl; }
};