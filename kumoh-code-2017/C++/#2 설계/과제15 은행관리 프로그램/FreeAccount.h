#pragma once
#include"Account.h"
#include"Screen.h"

class FreeAccount : public Account{
private:
	double free_balance;
public:
	FreeAccount(int accountNumber, int password, int balance);
	double getBalance() { return free_balance; }
	virtual void credit(int money); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
	virtual void debit(int money); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
};