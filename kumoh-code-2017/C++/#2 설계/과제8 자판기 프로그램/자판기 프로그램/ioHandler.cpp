#include "ioHandler.h"

int ioHandler::getMenu()
{
	cout << "------ ���Ǳ� ���α׷� ------" << endl;
	cout << "------ 1. ���� ����    ------" << endl;
	cout << "------ 2. ��ǰ ����    ------" << endl;
	cout << "------ 3. �ܵ� ��ȯ    ------" << endl;
	cout << "------ 4. ���α׷� ����------" << endl;

	int menu = getInteger(" ���� : ");

	if (menu >= COIN_DEPOSIT && menu <= EXIT)
	{
		return menu;
	}
}

int ioHandler::getCoinMenu()
{
	cout << "----- �������� -----" << endl;
	cout << "----- [1] 10�� -----" << endl;
	cout << "----- [2] 50�� -----" << endl;
	cout << "----- [3] 100��-----" << endl;
	cout << "----- [4] 500��-----" << endl;

	int menu = getInteger(" ���� : ");

	if (menu >= 1 && menu <= 4)
	{
		return menu;
	}
}

int ioHandler::getSelectMenu()
{
	CanStorage c_list;
	cout << "------------- ����� �޴� ------------" << endl;
	cout << "----- [1] pepsiCoke (600��)      -----" << endl;
	cout << "----- [2] sevenStarCider (600��) -----" << endl;
	cout << "----- [3] orangeJuice (500��)    -----" << endl;
	cout << "----- [4] water (400��)          -----" << endl;
	cout << "----- [5] mountinDew (600��)     -----" << endl;
	cout << "----- [6] lemonaide (500��)      -----" << endl;

	int menu = getInteger(" ���� : ");

	if (menu >= 1 && menu <= 6)
	{
		return menu;
	}
}

void ioHandler::displayMenu(CanStorage& c_list)
{
	for (int i = 0; i < 6; i++)
	{
		cout << "[" << c_list.getCanList(i).getId() << "] " << c_list.getCanList(i).getName() << " (" << c_list.getCanList(i).getPrice() << "��) " << " ��� : " << c_list.getCanList(i).getQuantity() << endl;
	}
}

int ioHandler::getInteger(string msg)
{
	int value;

	cout << msg;
	cin >> value;

	return value;
}

string ioHandler::getString(string msg)
{
	string value;

	cout << msg;
	cin >> value;

	return value;
}

void ioHandler::loadCanStorage(string fileName, CanStorage& c_list) // ���� �б��
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	string id;
	string name;
	int price;
	int stock_quantity;

	while (!fin.eof()) // ������ ���� �������� �ʾҴٸ� ��� �ݺ�
	{
		fin >> id >> name >> price >> stock_quantity; // ������ ���� ����
		Can c(id, name, price, stock_quantity); // Can �ӽ� ��ü ����
		c_list.insertCanStorage(c);
		c_list.plusCount();
	}

	fin.close();
}