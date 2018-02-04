#include "IoHandler.h"

char IoHandler::getMenu()
{
	char menu_type;
	putNewLine();
	menu_type = getChar("프로그램을 선택하세요.([I]nput Data / [Q]uit) : ");

	if (menu_type == 'i' || menu_type == 'I' || menu_type == 'q' || menu_type == 'Q')
	{
		return menu_type;
	}
	else
	{
		putString(" 잘못 입력하셨습니다 ");
	}
}

char IoHandler::getSortMenu()
{
	char menu_type;

	putNewLine();
	menu_type = getChar("프로그램을 선택하세요.([R]andom / [I]ncrease / [D]ecrease / [Q]uit) : ");

	if (menu_type == 'r' || menu_type == 'R' || menu_type == 'i' || menu_type == 'I' || menu_type == 'd' || menu_type == 'D' || menu_type == 'q' || menu_type == 'Q')
	{
		return menu_type;
	}
	else
	{
		putString(" 잘못 입력하셨습니다 ");
	}
}

void IoHandler::getTypeMenu(string type)
{
	cout << "---------- " << type << "                          ----------" << endl;
	cout << "---------- [0]삽입정렬                     ----------" << endl;
	cout << "---------- [1]이원삽입정렬                 ----------" << endl;
	cout << "---------- [2]연결삽입정렬                 ----------" << endl;
	cout << "---------- [3]퀵정렬                       ----------" << endl;
	cout << "---------- [4]median of three 퀵정렬       ----------" << endl;
	cout << "---------- [5]median of three 퀵정렬(반복) ----------" << endl;
	cout << "---------- [6]라이브러리퀵정렬             ----------" << endl;
	cout << "---------- [7]재귀합병정렬                 ----------" << endl;
	cout << "---------- [8]반복합병정렬                 ----------" << endl;
	cout << "---------- [9]자연합병정렬                 ----------" << endl;
	cout << "---------- [10]힙정렬                      ----------" << endl;
	cout << "---------- [11]버블정렬                    ----------" << endl;
	cout << "---------- [12]선택정렬                    ----------" << endl;
	cout << "---------- 입력 범위 [0] ~ [12]            ----------" << endl;
}

int IoHandler::getInteger(string msg)
{
	cout << msg;
	int i;
	cin >> i;
	return i;
}

string IoHandler::getString(string msg)
{
	cout << msg;
	string str;
	cin >> str;
	return str;
}

char IoHandler::getChar(string msg)
{
	cout << msg;
	char c;
	cin >> c;
	return c;
}