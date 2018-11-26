#include"Transaction.h"

Transaction::Transaction(){
	accountNumber = 0;
}

Transaction::Transaction(int accountNumber, Screen screen, BankDatabase bankDB){
	this->accountNumber = accountNumber;
	this->screen = screen;
	this->bankDB = bankDB;
}

int Transaction::getAccountNumber(){
	return accountNumber;
}

Screen Transaction::getScreen(){
	return screen;
}

BankDatabase Transaction::getBankDataBalance(){
	return bankDB;
}

