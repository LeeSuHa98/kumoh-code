#include"BankDatabase.h"

BankDatabase::BankDatabase(){
	accounts = new Account*[capacity];
 	accounts[0] = new FreeAccount(1, 1201, 1000);
	accounts[1] = new MinusAccount(2, 1202, 1000);	
}

Account* BankDatabase::getAccount(int accountNumber){ // 현재 BankDataBase내에 존재하는 계좌를 리턴

	for (int i = 0; i < capacity; i++){
		if (accountNumber == accounts[i]->getAccountNumber())
			return accounts[i];
	}
	throw "null"; //계좌번호가 존재하지 않을시 null값 전파(나중에 계좌개설이나 계좌삭제할때 사용하시면 됩니다.)
}

bool BankDatabase::authenticateUser(int accountNumber, int password){
	try{
		Account *acc = getAccount(accountNumber);
		return acc->checkPassword(password);
	}
	catch (char *){ //null값이 리턴된것을 전파받았을 경우에 false반환(예외처리)
		return false;
	}
}

int BankDatabase::getBalance(int accountNumber){
	return getAccount(accountNumber)->getBalance();
}

void BankDatabase::credit(int accountNumber, int money){
	getAccount(accountNumber)->credit(money);
}

void BankDatabase::debit(int accountNumber, int money){
	getAccount(accountNumber)->debit(money);
}

