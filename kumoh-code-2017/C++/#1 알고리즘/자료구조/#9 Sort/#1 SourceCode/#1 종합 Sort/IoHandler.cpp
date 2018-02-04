#include "IoHandler.h"

char IoHandler::getMenu()
{
	char menu_type;
	putNewLine();
	menu_type = getChar("���α׷��� �����ϼ���.([I]nput Data / [Q]uit) : ");

	if (menu_type == 'i' || menu_type == 'I' || menu_type == 'q' || menu_type == 'Q')
	{
		return menu_type;
	}
	else
	{
		putString(" �߸� �Է��ϼ̽��ϴ� ");
	}
}

char IoHandler::getSortMenu()
{
	char menu_type;

	putNewLine();
	menu_type = getChar("���α׷��� �����ϼ���.([R]andom / [I]ncrease / [D]ecrease / [Q]uit) : ");

	if (menu_type == 'r' || menu_type == 'R' || menu_type == 'i' || menu_type == 'I' || menu_type == 'd' || menu_type == 'D' || menu_type == 'q' || menu_type == 'Q')
	{
		return menu_type;
	}
	else
	{
		putString(" �߸� �Է��ϼ̽��ϴ� ");
	}
}

void IoHandler::getTypeMenu(string type)
{
	cout << "---------- " << type << "                          ----------" << endl;
	cout << "---------- [0]��������                     ----------" << endl;
	cout << "---------- [1]�̿���������                 ----------" << endl;
	cout << "---------- [2]�����������                 ----------" << endl;
	cout << "---------- [3]������                       ----------" << endl;
	cout << "---------- [4]median of three ������       ----------" << endl;
	cout << "---------- [5]median of three ������(�ݺ�) ----------" << endl;
	cout << "---------- [6]���̺귯��������             ----------" << endl;
	cout << "---------- [7]����պ�����                 ----------" << endl;
	cout << "---------- [8]�ݺ��պ�����                 ----------" << endl;
	cout << "---------- [9]�ڿ��պ�����                 ----------" << endl;
	cout << "---------- [10]������                      ----------" << endl;
	cout << "---------- [11]��������                    ----------" << endl;
	cout << "---------- [12]��������                    ----------" << endl;
	cout << "---------- �Է� ���� [0] ~ [12]            ----------" << endl;
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