#include "IoHandler.h"

int IoHandler::getMenu()
{
	int menu_type;

	cout << "---------- [1]modulo ����(%) ���� 16���� LSB ���� ��� �����ϴ� radix sort                ----------" << endl;
	cout << "---------- [2]masking(&)�� shift ����(>>)�������� 16���� LSB���� ��� �����ϴ� radix sort ----------" << endl;
	cout << "---------- [3]modulo ����(%) ���� 10���� LSB ���� ��� �����ϴ� radix sort                ----------" << endl;
	cout << "---------- [4]iterativeMergeSort                                                          ----------" << endl;
	cout << "---------- [5]Exit                                                                        ----------" << endl;

	menu_type = getInteger("���� : ");

	if (menu_type == 1 || menu_type == 2 || menu_type == 3 || menu_type == 4 || menu_type == 5)
	{
		return menu_type;
	}
	else
	{
		putString(" �߸� �Է��ϼ̽��ϴ� ");
	}
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