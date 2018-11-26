#pragma once
#include"Transaction.h"
#include"Keypad.h"

class Withdrawal : public Transaction {
private:
	int money;
	Keypad keypad;
	static const int stop = -999;
	int getWithdrawalAmountFromKBD(); // 메세지 출력후 출금액 입력받음
public:
	Withdrawal(int accountNumber, Screen screen, BankDatabase bankDB,Keypad keypad);
	virtual void execute(); //(다형성이므로 virtual명시하였습니다.)
};