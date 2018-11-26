#include"MinusAccount.h"

MinusAccount::MinusAccount(int accountNumber, int password, int balance) :Account(accountNumber, password, balance){

}

//====메소드 재정의 (다형성) =====

void MinusAccount::credit(int money){
	balance = balance + money;
}

void MinusAccount::debit(int money){
	balance = balance - money;
}
