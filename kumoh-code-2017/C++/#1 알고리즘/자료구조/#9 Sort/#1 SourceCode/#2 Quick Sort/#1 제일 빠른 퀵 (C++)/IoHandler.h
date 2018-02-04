#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class IoHandler
{
private:

public:
	IoHandler() {}
	~IoHandler() {}

	void getLine() { cout << endl; }

	void putString(string msg) { cout << msg; }
};