#include"Deposit.h"

Deposit::Deposit(int accountNumber, Screen screen, BankDatabase bankDB,Keypad keypad) : Transaction( accountNumber,  screen,  bankDB){
	this->keypad = keypad;
}

int Deposit::getDepositAmountFromKBD(){
	Screen screen = getScreen();
	screen.displayMsg("입금액을 입력하시오(취소하려면 -999): ");
	int balance = keypad.getInput();

	if (balance != stop)
		return balance;
	else
		return NULL;
}

void Deposit::execute(){
	BankDatabase bankDatabse = getBankDataBalance();
	Screen screen = getScreen();
	this->money = getDepositAmountFromKBD();
	bankDatabse.credit(getAccountNumber(), bankDatabse.setBalance(money));// setbalance를 통해 간단히 표현(다형성의 장점)
}