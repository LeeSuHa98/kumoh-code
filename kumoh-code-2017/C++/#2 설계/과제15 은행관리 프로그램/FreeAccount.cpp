#include"FreeAccount.h"

FreeAccount::FreeAccount(int accountNumber, int password, int balance) :Account(accountNumber, password, balance){
	
}

 //====�޼ҵ� ������ (������) =====

void FreeAccount::credit(int money){
	balance = balance+ money;
}

void FreeAccount::debit(int money){ 
	Screen screen;
	if ((balance-money) < 0){
		screen.displayMsg("�ܰ� 0�� �̸��Դϴ�.(����� ����մϴ�.)");
	}
	else{
		balance = balance - money;
	}
}