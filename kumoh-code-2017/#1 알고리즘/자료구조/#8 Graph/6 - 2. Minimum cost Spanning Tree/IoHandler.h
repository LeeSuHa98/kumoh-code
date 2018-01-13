#pragma once
#include <iostream>
#include <string>
#include "HeapNode.h"

using namespace std;

class IoHandler
{
public:
	IoHandler() {}
	~IoHandler() {}

	char getMenu();
	char getSearchGraphMenu();

	string getString(string msg);
	char getChar(string msg);

	void putString(string msg) { cout << msg; }
	void putInteger(int num) { cout << num; }
	void putNewLine() { cout << endl; }
	void printConnectedComponent(int data) { cout << data << " "; }
};