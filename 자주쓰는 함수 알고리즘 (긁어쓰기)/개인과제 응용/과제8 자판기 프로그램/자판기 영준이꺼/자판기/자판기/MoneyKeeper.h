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

	void increase_money(int index); // Coin �� �Ű������� �����ʰ� index�� �� ������ ��ü���� Ư���� �ִ��� ������ �����ؾ��ϱ⋚��
	void decrease_money(int money); // money ������ �Ű������� �޴°��� ���������� ����� ������ �ȳ�
	void changeReturn(){total_money = 0;}

	int getMoney(){return total_money;}
};

