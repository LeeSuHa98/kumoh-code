#pragma once
#include"Screen.h"

class Account {
private:
	int accountNumber;
	int password;
protected: 
	int balance;
public:
	Account();
	Account(int accountNumber, int password, int balance);
	bool checkPassword(int password);
	double getBalance() { return balance; }
	int getPassword() { return password; }
	int getAccountNumber() { return accountNumber; }
	virtual int setBalance(int balance);
	virtual void credit(int balance); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
	virtual void debit(int balance); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
};