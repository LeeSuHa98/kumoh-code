#include "IoHandler.h"

char IoHandler::getMenu()
{
	char menu_type;

	while (1)
	{
		putNewLine();
		menu_type = getChar("���α׷��� �����ϼ���.([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) : ");

		if (menu_type == 's' || menu_type == 'S' || menu_type == 'm' || menu_type == 'M' || menu_type == 't' || menu_type == 'T' || menu_type == 'q' || menu_type == 'Q')
		{
			return menu_type;
		}
		else
		{
			putString(" �߸� �Է��ϼ̽��ϴ� ");
		}
	}
}

char IoHandler::getSearchGraphMenu()
{
	char menu_type;

	while (1)
	{
		putNewLine();
		menu_type = getChar("���α׷��� �����ϼ���.([M]atrix / [L]ist / [Q]uit) : ");

		if (menu_type == 'm' || menu_type == 'M' || menu_type == 'l' || menu_type == 'L' || menu_type == 'q' || menu_type == 'Q')
		{
			return menu_type;
		}
		else
		{
			putString(" �߸� �Է��ϼ̽��ϴ� ");
		}
	}
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