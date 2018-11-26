#include"FreeAccount.h"

FreeAccount::FreeAccount(int accountNumber, int password, int balance) :Account(accountNumber, password, balance){
	
}

 //====메소드 재정의 (다형성) =====

void FreeAccount::credit(int money){
	balance = balance+ money;
}

void FreeAccount::debit(int money){ 
	Screen screen;
	if ((balance-money) < 0){
		screen.displayMsg("잔고가 0원 미만입니다.(출금을 취소합니다.)");
	}
	else{
		balance = balance - money;
	}
}