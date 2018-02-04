#include "ioHandler.h"

int ioHandler::getMenu()
{
	while (1)
	{
		putString("------ 학생관리 프로그램 ------");
		putString("------ 1. 학생 정보 등록 ------");
		putString("------ 2. 학생 정보 삭제 ------");
		putString("------ 3. 학생 정보 수정 ------");
		putString("------ 4. 학생 정보 출력 ------");
		putString("------ 5. 프로그램 종료  ------");

		int menu = getInteger(" 선택 : ");
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

	id = getInteger(" 학번 : ");
	name = getString(" 이름 : ");
	age = getInteger(" 나이 : ");
	phone = getString(" 전화번호 : ");

	Student s(id, name, age, phone);
	return s;
}

void ioHandler::putStudent(Student s)
{
	cout << " 학번 : " << s.getId() << "\n";
	cout << " 이름 : " << s.getName() << "\n";
	cout << " 나이 : " << s.getAge() << "\n";
	cout << " 전화번호 : " << s.getPhone();
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