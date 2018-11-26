#pragma once
#include "Transaction.h"
class BalanceInquiry : public Transaction {

public:
	BalanceInquiry(int accountNumber, Screen screen, BankDatabase bankDB);
	virtual void execute(); //(다형성이므로 virtual명시하였습니다.)
};