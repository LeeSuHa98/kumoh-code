#include"Account.h"

Account::Account(){
	accountNumber = 0;
	password = 0;
	balance = 0;
}

Account::Account(int accountNumber, int password, int balance){
	this->accountNumber = accountNumber;
	this->password = password;
	this->balance = balance;
}

bool Account::checkPassword(int password){
	if (this->password == password){
		return true;
	}
	else
		return false;
}

int Account::setBalance(int balance){ //����ݽ� �Է¹������� �м��Ͽ� stop���� �ƴ����� ����
	Screen screen;
	this->balance = balance;
	if (balance != -999){
		return balance;
	}
}

void Account::credit(int money){
	balance = balance+money;
}

void Account::debit(int money){
	balance = balance-money;
}

