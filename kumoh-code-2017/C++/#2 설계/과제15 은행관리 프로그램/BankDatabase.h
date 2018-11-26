#pragma once
#include"Account.h"
#include"Screen.h"
#include"FreeAccount.h"
#include"MinusAccount.h"

class BankDatabase : public Account {
private:
	Account **accounts; // **�� ����ϴ� ����:������ ������ 1.������ ���� 2.������ ���� �ΰ����̸� ���߿� ���°������� �Լ��� �߰��ϽǶ� �����մϴ�. 
	int capacity=2; //�ʱ⿡ 2���� ������
public:
	BankDatabase(); // 2���� ���»���(FreeAccount,MinusAccount)
	Account* getAccount(int accountNumber);
	bool authenticateUser(int accountNumber, int password);
	int getBalance(int accountNumber);
	virtual void credit(int accountNumber, int money);//�Ա�(�������̹Ƿ� virtual����Ͽ����ϴ�.)
	virtual void debit(int accountNumber, int money);//���(�������̹Ƿ� virtual����Ͽ����ϴ�.)
};