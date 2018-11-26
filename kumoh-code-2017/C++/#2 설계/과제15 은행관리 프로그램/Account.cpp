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

int Account::setBalance(int balance){ //입출금시 입력받은값을 분석하여 stop인지 아닌지를 구별
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

