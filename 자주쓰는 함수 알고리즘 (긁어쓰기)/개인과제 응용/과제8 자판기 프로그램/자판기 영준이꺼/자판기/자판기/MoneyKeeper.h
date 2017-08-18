#pragma once
#include <iostream>
using namespace std;
class MoneyKeeper
{
private:
	int total_money;
public:
	MoneyKeeper(void);
	~MoneyKeeper(void);

	void increase_money(int index); // Coin 을 매개변수로 주지않고 index를 준 이유는 객체지향 특성상 최대한 정보를 은닉해야하기떄문
	void decrease_money(int money); // money 정보를 매개변수로 받는것은 좋지않으나 방법이 생각이 안남
	void changeReturn(){total_money = 0;}

	int getMoney(){return total_money;}
};

