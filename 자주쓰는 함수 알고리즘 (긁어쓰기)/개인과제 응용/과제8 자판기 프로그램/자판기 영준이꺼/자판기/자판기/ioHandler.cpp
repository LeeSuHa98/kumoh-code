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

	int canNumber;           // ĵ��ȣ
 	string canName;          // ĵ�̸�
	int price;               // ����
	int amount;              // ����

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
	cout << "[1] �������� [2] ��ǰ���� [3] �ܵ���ȯ [4] ����" << endl;
	cout << "Select -> "; 
	cin >> index;

	if(index >= 1 && index <=4)
		return index;
	else
		cout << "�ٽ� �Է��Ͻÿ� " << endl;
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
		cout << cs.getCanList(i).name << " : " << cs.getCanList(i).price << "�� , ���� ��� : " << cs.getCanList(i).stock_quantity << endl;
	cout << "---------------------------------------------------------" << endl;
}

void ioHandler::printRemainedCoin(MoneyKeeper mk)
{
	cout << "---------------------------------------------------------" << endl;
	cout << "���� �ܾ��� " << mk.getMoney() << "�� �Դϴ�. " << endl;
	cout << "---------------------------------------------------------" << endl;
}