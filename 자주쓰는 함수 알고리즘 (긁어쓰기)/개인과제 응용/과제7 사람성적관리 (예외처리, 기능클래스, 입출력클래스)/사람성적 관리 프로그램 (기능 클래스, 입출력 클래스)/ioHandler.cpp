#include "ioHandler.h"

int ioHandler::getMenu()
{
	putString("------ 성적관리 프로그램 ------");
	putString("------ 1. 사람 성적 등록 ------");
	putString("------ 2. 사람 성적 삭제 ------");
	putString("------ 3. 사람 성적 출력 ------");
	putString("------ 4. 프로그램 종료  ------");

	int menu = getInteger(" 선택 : ");
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

	//name = getString(" 이름 : ");
	korean = getInteger(" 국어성적 : ");
	english = getInteger(" 영어성적 : ");
	math = getInteger(" 수학성적 : ");

	Person p(name, korean, english, math);
	return p;
}

void ioHandler::putStudent(Person p)
{
	cout << endl;
	cout << " 이름 : " << p.getName() << "\n";
	cout << " 국어성적 : " << p.getKorean() << "\n";
	cout << " 영어성적 : " << p.getEnglish() << "\n";
	cout << " 수학성적 : " << p.getMath() << "\n";
	cout << " 평균성적 : " << p.getAverage() << "\n";
	cout << " 등급 : " << p.getGrade();
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