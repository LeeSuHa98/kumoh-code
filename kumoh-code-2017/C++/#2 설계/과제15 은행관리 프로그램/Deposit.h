#pragma once
#include"Transaction.h"
#include"Keypad.h"

class Deposit : public Transaction {
private:
	int money;
	Keypad keypad;
	static const int stop = -999;
	int getDepositAmountFromKBD();
public:
	Deposit(int accountNumber, Screen screen, BankDatabase bankDB,Keypad keypad);
	virtual void execute(); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
 

};