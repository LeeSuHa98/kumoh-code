#include"BankDatabase.h"

BankDatabase::BankDatabase(){
	accounts = new Account*[capacity];
 	accounts[0] = new FreeAccount(1, 1201, 1000);
	accounts[1] = new MinusAccount(2, 1202, 1000);	
}

Account* BankDatabase::getAccount(int accountNumber){ // ���� BankDataBase���� �����ϴ� ���¸� ����

	for (int i = 0; i < capacity; i++){
		if (accountNumber == accounts[i]->getAccountNumber())
			return accounts[i];
	}
	throw "null"; //���¹�ȣ�� �������� ������ null�� ����(���߿� ���°����̳� ���»����Ҷ� ����Ͻø� �˴ϴ�.)
}

bool BankDatabase::authenticateUser(int accountNumber, int password){
	try{
		Account *acc = getAccount(accountNumber);
		return acc->checkPassword(password);
	}
	catch (char *){ //null���� ���ϵȰ��� ���Ĺ޾��� ��쿡 false��ȯ(����ó��)
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

