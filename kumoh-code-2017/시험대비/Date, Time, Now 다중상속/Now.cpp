#include "Now.h"

void Now::print()
{
	if (mode == true)
	{
		cout << "Now is " << year << "-" << month << "-" << date << ", " << hour << ":" << minute << ":" << second << ":" << microsec << endl;
	}
	else
	{
		cout << "지금은 " << year << "년 " << month << "월 " << date << "일 " << hour << "시 " << minute << "분 " << second << "초 " << microsec << "밀리초입니다." << endl;
	}
}