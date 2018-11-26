#pragma once
#include"Transaction.h"
#include"Keypad.h"

class Withdrawal : public Transaction {
private:
	int money;
	Keypad keypad;
	static const int stop = -999;
	int getWithdrawalAmountFromKBD(); // �޼��� ����� ��ݾ� �Է¹���
public:
	Withdrawal(int accountNumber, Screen screen, BankDatabase bankDB,Keypad keypad);
	virtual void execute(); //(�������̹Ƿ� virtual����Ͽ����ϴ�.)
};