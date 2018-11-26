#include"Deposit.h"

Deposit::Deposit(int accountNumber, Screen screen, BankDatabase bankDB,Keypad keypad) : Transaction( accountNumber,  screen,  bankDB){
	this->keypad = keypad;
}

int Deposit::getDepositAmountFromKBD(){
	Screen screen = getScreen();
	screen.displayMsg("�Աݾ��� �Է��Ͻÿ�(����Ϸ��� -999): ");
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
	bankDatabse.credit(getAccountNumber(), bankDatabse.setBalance(money));// setbalance�� ���� ������ ǥ��(�������� ����)
}