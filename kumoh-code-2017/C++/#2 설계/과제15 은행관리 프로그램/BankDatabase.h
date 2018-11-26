#pragma once
#include"Account.h"
#include"Screen.h"
#include"FreeAccount.h"
#include"MinusAccount.h"

class BankDatabase : public Account {
private:
	Account **accounts; // **을 사용하는 이유:저장할 정보가 1.계좌의 정보 2.계좌의 종류 두가지이며 나중에 계좌개설같은 함수를 추가하실때 유용합니다. 
	int capacity=2; //초기에 2개의 값생성
public:
	BankDatabase(); // 2개의 계좌생성(FreeAccount,MinusAccount)
	Account* getAccount(int accountNumber);
	bool authenticateUser(int accountNumber, int password);
	int getBalance(int accountNumber);
	virtual void credit(int accountNumber, int money);//입금(다형성이므로 virtual명시하였습니다.)
	virtual void debit(int accountNumber, int money);//출금(다형성이므로 virtual명시하였습니다.)
};