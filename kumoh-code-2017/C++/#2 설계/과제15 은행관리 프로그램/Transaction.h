#pragma once
#include"Account.h"
#include"Screen.h"
#include"BankDatabase.h"

class Transaction {
private:
	int accountNumber;
	Screen screen;
	BankDatabase bankDB;
public:
	Transaction();
	Transaction(int accountNumber, Screen screen, BankDatabase bankDB);
	int getAccountNumber();
	Screen getScreen();
	BankDatabase getBankDataBalance();
	virtual void execute() = 0; // 트랙잭션실행 추상메소드 parent메소드 child클래스에서 재정의 하므로 0으로 초기화
};