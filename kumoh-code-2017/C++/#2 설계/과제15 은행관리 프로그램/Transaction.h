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
	virtual void execute() = 0; // Ʈ����ǽ��� �߻�޼ҵ� parent�޼ҵ� childŬ�������� ������ �ϹǷ� 0���� �ʱ�ȭ
};