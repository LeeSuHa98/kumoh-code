#pragma once
#include "Can.h"

class MoneyKeeper
{
private:
	int money; // �ݾ�
public:
	MoneyKeeper() { money = 0; }
	~MoneyKeeper() {}

	// ���� ������ ���� ����
	void plusMoney(int index);
	// ����� ���� �� ���� ����
	void minusMoney(int index);
	// �ܾ� ��
	int compareMoney(int index);
	// ���� �Ž����� ���� ��ȯ
	void returnMoney();
};