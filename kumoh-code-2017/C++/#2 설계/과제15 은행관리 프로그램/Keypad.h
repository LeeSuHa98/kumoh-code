#pragma once
#include<iostream>
#include<string>
using namespace std;

class Keypad {
private:
	string input;
public:
	Keypad();
	int getInput(); // Ű����κ��� int ��ȯ
};