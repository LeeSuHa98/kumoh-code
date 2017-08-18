#include "ioHandler.h"

int ioHandler::getMenu()
{
	putString("------ �������� ���α׷� ------");
	putString("------ 1. ��� ���� ��� ------");
	putString("------ 2. ��� ���� ���� ------");
	putString("------ 3. ��� ���� ��� ------");
	putString("------ 4. ���α׷� ����  ------");

	int menu = getInteger(" ���� : ");
	if (menu >= INSERT && menu <= EXIT)
	{
		return menu;
	}
}

Person ioHandler::getStudent(string name, PersonList& p_list)
{
	//string name;
	int korean;
	int english;
	int math;

	//name = getString(" �̸� : ");
	korean = getInteger(" ����� : ");
	english = getInteger(" ����� : ");
	math = getInteger(" ���м��� : ");

	Person p(name, korean, english, math);
	return p;
}

void ioHandler::putStudent(Person p)
{
	cout << endl;
	cout << " �̸� : " << p.getName() << "\n";
	cout << " ����� : " << p.getKorean() << "\n";
	cout << " ����� : " << p.getEnglish() << "\n";
	cout << " ���м��� : " << p.getMath() << "\n";
	cout << " ��ռ��� : " << p.getAverage() << "\n";
	cout << " ��� : " << p.getGrade();
	cout << endl;
}

string ioHandler::getString(string msg)
{
	string value;

	cout << msg;
	cin >> value;

	return value;
}

int ioHandler::getInteger(string msg)
{
	int value;

	cout << msg;
	cin >> value;

	return value;
}

double ioHandler::getDouble(string msg)
{
	double value;

	cout << msg;
	cin >> value;

	return value;
}