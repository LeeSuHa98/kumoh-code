#include"Withdrawal.h"

Withdrawal::Withdrawal(int accountNumber, Screen screen, BankDatabase bankDB, Keypad keypad) : Transaction(accountNumber, screen, bankDB){
	this->keypad = keypad;
}

int Withdrawal::getWithdrawalAmountFromKBD(){
	Screen screen = getScreen();
	screen.displayMsg("출금액을 입력하시오(취소하려면 -999): ");
	int balance = keypad.getInput();
	if (balance != stop)
		return balance;
	else
		return NULL;
}

void Withdrawal::execute(){
	BankDatabase bankDatabse = getBankDataBalance();
	Screen screen = getScreen();
	this->money = getWithdrawalAmountFromKBD();
	bankDatabse.debit(getAccountNumber(), bankDatabse.setBalance(money)); // setbalance를 통해 간단히 표현 (다형성의 장점)
	
}