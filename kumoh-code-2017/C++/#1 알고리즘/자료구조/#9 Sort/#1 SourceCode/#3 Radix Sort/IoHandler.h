#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class IoHandler
{
public:
	IoHandler() {}
	~IoHandler() {}
	
	int getMenu();

	int getInteger(string msg);
	string getString(string msg);
	char getChar(string msg);

	void putString(string msg) { cout << msg; }
	void putInteger(int num) { cout << num; }
	void putNewLine() { cout << endl; }
};