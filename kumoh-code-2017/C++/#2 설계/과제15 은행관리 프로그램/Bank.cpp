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
		screen.displayMsg("계좌번호 입력: ");
		int accountNumber = keypad.getInput();
		screen.displayMsg("비밀번호 입력: ");
		int password = keypad.getInput();

		userAuthenticated = bankdatabase.authenticateUser(accountNumber, password);
		if (userAuthenticated){
			currentAccountNumber = accountNumber;
			numCheck = false;
		}
		else{
			screen.displayMsg("잘못된 비밀번호입니다. 다시입력해주세요.");
		}
	}
}


int Bank::displayMenu_Account(){
	screen.displayMsg("======작업선택창======");
	screen.displayMsg("1. 잔고조회");
	screen.displayMsg("2. 출금");
	screen.displayMsg("3. 입금");
	screen.displayMsg("4. exit(종료)");
	screen.displayMsg("======================");
	screen.displayMsg("번호입력: ");

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
			screen.displayMsg("프로그램을 종료합니다.");
			programCheck = false;
			break;
		default:
			screen.displayMsg("잘못된 값 입력");
			break;
		}
	}
}