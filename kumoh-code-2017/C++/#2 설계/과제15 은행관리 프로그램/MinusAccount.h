#pragma once
#include"Account.h"

class MinusAccount : public Account {
private:
	int Minus_balance;
public:
	MinusAccount(int accountNumber, int password, int balance);
	double getBalance() { return Minus_balance; }
	virtual void credit(int money); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
	virtual void debit(int money); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)

};