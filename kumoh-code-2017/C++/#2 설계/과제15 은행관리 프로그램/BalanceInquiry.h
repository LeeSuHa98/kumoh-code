#pragma once
#include "Transaction.h"
class BalanceInquiry : public Transaction {

public:
	BalanceInquiry(int accountNumber, Screen screen, BankDatabase bankDB);
	virtual void execute(); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
};