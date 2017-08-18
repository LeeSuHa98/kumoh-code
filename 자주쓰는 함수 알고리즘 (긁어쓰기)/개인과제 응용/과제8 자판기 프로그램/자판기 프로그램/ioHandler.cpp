#include "ioHandler.h"

int ioHandler::getMenu()
{
	cout << "------ 자판기 프로그램 ------" << endl;
	cout << "------ 1. 동전 투입    ------" << endl;
	cout << "------ 2. 상품 선택    ------" << endl;
	cout << "------ 3. 잔돈 반환    ------" << endl;
	cout << "------ 4. 프로그램 종료------" << endl;

	int menu = getInteger(" 선택 : ");

	if (menu >= COIN_DEPOSIT && menu <= EXIT)
	{
		return menu;
	}
}

int ioHandler::getCoinMenu()
{
	cout << "----- 동전투입 -----" << endl;
	cout << "----- [1] 10원 -----" << endl;
	cout << "----- [2] 50원 -----" << endl;
	cout << "----- [3] 100원-----" << endl;
	cout << "----- [4] 500원-----" << endl;

	int menu = getInteger(" 선택 : ");

	if (menu >= 1 && menu <= 4)
	{
		return menu;
	}
}

int ioHandler::getSelectMenu()
{
	CanStorage c_list;
	cout << "------------- 음료수 메뉴 ------------" << endl;
	cout << "----- [1] pepsiCoke (600원)      -----" << endl;
	cout << "----- [2] sevenStarCider (600원) -----" << endl;
	cout << "----- [3] orangeJuice (500원)    -----" << endl;
	cout << "----- [4] water (400원)          -----" << endl;
	cout << "----- [5] mountinDew (600원)     -----" << endl;
	cout << "----- [6] lemonaide (500원)      -----" << endl;

	int menu = getInteger(" 선택 : ");

	if (menu >= 1 && menu <= 6)
	{
		return menu;
	}
}

void ioHandler::displayMenu(CanStorage& c_list)
{
	for (int i = 0; i < 6; i++)
	{
		cout << "[" << c_list.getCanList(i).getId() << "] " << c_list.getCanList(i).getName() << " (" << c_list.getCanList(i).getPrice() << "원) " << " 재고 : " << c_list.getCanList(i).getQuantity() << endl;
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

void ioHandler::loadCanStorage(string fileName, CanStorage& c_list) // 파일 읽기용
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	string id;
	string name;
	int price;
	int stock_quantity;

	while (!fin.eof()) // 파일의 끝에 도달하지 않았다면 계속 반복
	{
		fin >> id >> name >> price >> stock_quantity; // 파일의 값을 읽음
		Can c(id, name, price, stock_quantity); // Can 임시 객체 생성
		c_list.insertCanStorage(c);
		c_list.plusCount();
	}

	fin.close();
}