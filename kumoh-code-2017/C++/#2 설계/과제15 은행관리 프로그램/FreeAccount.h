#pragma once
#include"Account.h"
#include"Screen.h"

class FreeAccount : public Account{
private:
	double free_balance;
public:
	FreeAccount(int accountNumber, int password, int balance);
	double getBalance() { return free_balance; }
	virtual void credit(int money); //(다형성이므로 virtual명시하였습니다.)
	virtual void debit(int money); //(다형성이므로 virtual명시하였습니다.)
};