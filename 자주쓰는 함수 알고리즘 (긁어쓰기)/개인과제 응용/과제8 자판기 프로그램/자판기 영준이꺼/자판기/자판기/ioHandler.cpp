#include "ioHandler.h"


ioHandler::ioHandler(void)
{
}


ioHandler::~ioHandler(void)
{
}

void ioHandler::loadCanList(string msg,CanStorage& cs)
{
	ifstream inf;
	inf.open(msg);

	int canNumber;           // 캔번호
 	string canName;          // 캔이름
	int price;               // 가격
	int amount;              // 수량

	while(!inf.eof())
	{
		inf >> canNumber >> canName >> price >> amount ;
		cs.insertCanList(canNumber,canName,price,amount);
	}
	inf.close();
}

int ioHandler::getMenu()
{
	int index;
	cout << "[1] 동전투입 [2] 상품선택 [3] 잔돈반환 [4] 종료" << endl;
	cout << "Select -> "; 
	cin >> index;

	if(index >= 1 && index <=4)
		return index;
	else
		cout << "다시 입력하시오 " << endl;
}

int ioHandler::getInteger(string msg)
{
	int select;
	cout << msg << endl;
	cout << "Select -> ";
	cin >> select;
	return select;
}

void ioHandler::printQuantity(CanStorage cs)
{
	cout << "---------------------------------------------------------" << endl;
	for(int i = 0 ; i < 6 ; i++)
		cout << cs.getCanList(i).name << " : " << cs.getCanList(i).price << "원 , 남은 재고 : " << cs.getCanList(i).stock_quantity << endl;
	cout << "---------------------------------------------------------" << endl;
}

void ioHandler::printRemainedCoin(MoneyKeeper mk)
{
	cout << "---------------------------------------------------------" << endl;
	cout << "남은 잔액은 " << mk.getMoney() << "원 입니다. " << endl;
	cout << "---------------------------------------------------------" << endl;
}