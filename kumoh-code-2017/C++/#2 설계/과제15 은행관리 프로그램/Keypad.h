#pragma once
#include<iostream>
#include<string>
using namespace std;

class Keypad {
private:
	string input;
public:
	Keypad();
	int getInput(); // 키보드로부터 int 반환
};