#include "Now.h"

void Now::print()
{
	if (mode == true)
	{
		cout << "Now is " << year << "-" << month << "-" << date << ", " << hour << ":" << minute << ":" << second << ":" << microsec << endl;
	}
	else
	{
		cout << "������ " << year << "�� " << month << "�� " << date << "�� " << hour << "�� " << minute << "�� " << second << "�� " << microsec << "�и����Դϴ�." << endl;
	}
}