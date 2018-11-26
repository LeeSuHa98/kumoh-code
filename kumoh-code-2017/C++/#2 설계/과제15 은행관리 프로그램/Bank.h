#pragma once
#include"Keypad.h"
#include"Screen.h"
#include"BankDatabase.h"
#include"Transaction.h"
#include"BalanceInquiry.h"
#include"Withdrawal.h"
#include"Deposit.h"
#include"FreeAccount.h"
#include"MinusAccount.h"

class Bank{
private:
	bool userAuthenticated;;
	int currentAccountNumber;
	int currentPassword;
	BankDatabase bankdatabase;
	Screen screen;
	Keypad keypad;
	static const int BALANCE_INQUIRY = 1, WITHDRAWAL = 2, DEPOSIT = 3, EXIT = 4;
	void authenticateUser();
	void performTransactions();
public:
	Bank();
	void run();
	int displayMenu_Account();
	Transaction* createTransaction(int type);
};