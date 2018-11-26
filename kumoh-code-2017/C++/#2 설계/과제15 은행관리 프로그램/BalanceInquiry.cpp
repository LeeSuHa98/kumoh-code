#include"BalanceInquiry.h"

BalanceInquiry::BalanceInquiry(int accountNumber, Screen screen, BankDatabase bankDB) :Transaction( accountNumber,  screen,  bankDB){

}

void BalanceInquiry::execute(){
	BankDatabase bankDatabase = getBankDataBalance();
	Screen screen = getScreen();
	int balance = bankDatabase.getBalance(getAccountNumber());
	screen.displayMsg("¿‹∞Ì: ");
	screen.displayAmount(balance);
	screen.displayMsg("");
}