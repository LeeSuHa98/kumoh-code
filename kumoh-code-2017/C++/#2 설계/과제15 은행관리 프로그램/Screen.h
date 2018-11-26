#pragma once
#include<iostream>
#include<string>
#include"Account.h"
using namespace std;

class Screen {
	string msg;
	double money;
public:
	Screen();
	void displayMsg(string msg);
	void displayAmount(double money);
	void displayrule();
};