#pragma once
#include"Account.h"

class MinusAccount : public Account {
private:
	int Minus_balance;
public:
	MinusAccount(int accountNumber, int password, int balance);
	double getBalance() { return Minus_balance; }
	virtual void credit(int money); //(다형성이므로 virtual명시하였습니다.)
	virtual void debit(int money); //(다형성이므로 virtual명시하였습니다.)

};