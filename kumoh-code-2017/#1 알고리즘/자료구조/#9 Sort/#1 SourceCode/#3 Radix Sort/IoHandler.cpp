#include "IoHandler.h"

int IoHandler::getMenu()
{
	int menu_type;

	cout << "---------- [1]modulo 연산(%) 으로 16진수 LSB 값을 얻어 정렬하는 radix sort                ----------" << endl;
	cout << "---------- [2]masking(&)과 shift 연산(>>)연산으로 16진수 LSB값을 얻어 정렬하는 radix sort ----------" << endl;
	cout << "---------- [3]modulo 연산(%) 으로 10진수 LSB 값을 얻어 정렬하는 radix sort                ----------" << endl;
	cout << "---------- [4]iterativeMergeSort                                                          ----------" << endl;
	cout << "---------- [5]Exit                                                                        ----------" << endl;

	menu_type = getInteger("선택 : ");

	if (menu_type == 1 || menu_type == 2 || menu_type == 3 || menu_type == 4 || menu_type == 5)
	{
		return menu_type;
	}
	else
	{
		putString(" 잘못 입력하셨습니다 ");
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