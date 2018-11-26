#include"Bank.h"

Bank::Bank(){
	userAuthenticated = false;
	currentAccountNumber = 0;
}

void Bank::run(){
	screen.displayrule();
	authenticateUser();
	if (userAuthenticated)
		performTransactions();
}

void Bank::authenticateUser(){
	bool numCheck = true;
	while (numCheck != false)
	{
		screen.displayMsg("���¹�ȣ �Է�: ");
		int accountNumber = keypad.getInput();
		screen.displayMsg("��й�ȣ �Է�: ");
		int password = keypad.getInput();

		userAuthenticated = bankdatabase.authenticateUser(accountNumber, password);
		if (userAuthenticated){
			currentAccountNumber = accountNumber;
			numCheck = false;
		}
		else{
			screen.displayMsg("�߸��� ��й�ȣ�Դϴ�. �ٽ��Է����ּ���.");
		}
	}
}


int Bank::displayMenu_Account(){
	screen.displayMsg("======�۾�����â======");
	screen.displayMsg("1. �ܰ���ȸ");
	screen.displayMsg("2. ���");
	screen.displayMsg("3. �Ա�");
	screen.displayMsg("4. exit(����)");
	screen.displayMsg("======================");
	screen.displayMsg("��ȣ�Է�: ");

	return keypad.getInput();
}

Transaction* Bank::createTransaction(int type){
	Transaction *temp;

	switch (type){
	case BALANCE_INQUIRY:
		temp = new BalanceInquiry(currentAccountNumber, screen, bankdatabase);
		break;
	case WITHDRAWAL:
		temp = new Withdrawal(currentAccountNumber, screen, bankdatabase, keypad);
		break;
	case DEPOSIT:
		temp = new Deposit(currentAccountNumber, screen, bankdatabase,keypad);
		break;
	default:
		break;
	}
	return temp;
}

void Bank::performTransactions(){
	int menuChoose;
	Transaction *currentTransaction;
	bool programCheck = true;

	while (programCheck!=false){
		switch (menuChoose = displayMenu_Account()){
		case BALANCE_INQUIRY:  case WITHDRAWAL:  case DEPOSIT:
			currentTransaction = createTransaction(menuChoose);
			currentTransaction->execute();
			break;
		case EXIT:
			screen.displayMsg("���α׷��� �����մϴ�.");
			programCheck = false;
			break;
		default:
			screen.displayMsg("�߸��� �� �Է�");
			break;
		}
	}
}