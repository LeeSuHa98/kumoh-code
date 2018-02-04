#pragma once
#include <iostream>
#include <string>

using namespace std;

class IoHandler
{
public:
	IoHandler() {}
	~IoHandler() {}

	char getMenu();
	char getSortMenu();
	void getTypeMenu(string type);

	int getInteger(string msg);
	string getString(string msg);
	char getChar(string msg);

	void putString(string msg) { cout << msg; }
	void putInteger(int num) { cout << num; }
	void putNewLine() { cout << endl; }
};