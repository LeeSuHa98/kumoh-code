#include"MinusAccount.h"

MinusAccount::MinusAccount(int accountNumber, int password, int balance) :Account(accountNumber, password, balance){

}

//====�޼ҵ� ������ (������) =====

void MinusAccount::credit(int money){
	balance = balance + money;
}

void MinusAccount::debit(int money){
	balance = balance - money;
}
