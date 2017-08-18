#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception
{
protected:
	int code;
	string str;
public:
	Exception() {}
	Exception(int code, string str)
	{
		this->code = code;
		this->str = str;
	}
	~Exception() {}

	int getCode() { return code; }
	string getStr() { return str; }
	void setCode(int code) { this->code = code; }
	void setStr(string str) { this->str = str; }
};