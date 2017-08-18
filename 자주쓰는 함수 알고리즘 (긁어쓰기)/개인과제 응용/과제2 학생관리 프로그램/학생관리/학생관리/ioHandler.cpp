#include "ioHandler.h"

int ioHandler::getMenu()
{
	while (1)
	{
		putString("------ �л����� ���α׷� ------");
		putString("------ 1. �л� ���� ��� ------");
		putString("------ 2. �л� ���� ���� ------");
		putString("------ 3. �л� ���� ���� ------");
		putString("------ 4. �л� ���� ��� ------");
		putString("------ 5. ���α׷� ����  ------");

		int menu = getInteger(" ���� : ");
		if (menu >= REGISTER && menu <= EXIT)
		{
			return menu;
		}
	}
}

Student ioHandler::getStudent()
{
	int id;
	string name;
	int age;
	string phone;

	id = getInteger(" �й� : ");
	name = getString(" �̸� : ");
	age = getInteger(" ���� : ");
	phone = getString(" ��ȭ��ȣ : ");

	Student s(id, name, age, phone);
	return s;
}

void ioHandler::putStudent(Student s)
{
	cout << " �й� : " << s.getId() << "\n";
	cout << " �̸� : " << s.getName() << "\n";
	cout << " ���� : " << s.getAge() << "\n";
	cout << " ��ȭ��ȣ : " << s.getPhone();
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