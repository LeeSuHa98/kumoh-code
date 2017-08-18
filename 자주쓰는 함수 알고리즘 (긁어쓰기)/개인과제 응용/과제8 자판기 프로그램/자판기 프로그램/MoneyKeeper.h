#pragma once
#include "Can.h"

class MoneyKeeper
{
private:
	int money; // 금액
public:
	MoneyKeeper() { money = 0; }
	~MoneyKeeper() {}

	// 동전 투입후 동전 증가
	void plusMoney(int index);
	// 음료수 구매 후 동전 감소
	void minusMoney(int index);
	// 잔액 비교
	int compareMoney(int index);
	// 남은 거스름돈 동전 반환
	void returnMoney();
};