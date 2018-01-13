#include "ioHandler.h"

int ioHandler::getMenu()
{
	cout << "------ 명단관리 프로그램 ------" << endl;
	cout << "------ 1. 명단 정보 등록 ------" << endl;
	cout << "------ 2. 명단 정보 삭제 ------" << endl;
	cout << "------ 3. 명단 정보 수정 ------" << endl;
	cout << "------ 4. 명단 정보 출력 ------" << endl;
	cout << "------ 5. 프로그램 종료  ------" << endl;

	int menu = getInteger(" 선택 : ");

	if (menu >= INSERT && menu <= EXIT)
	{
		return menu;
	}
}

int ioHandler::getInteger(string msg)
{
	int value;

	cout << msg;
	cin >> value;

	return value;
}

string ioHandler::getString(string msg)
{
	string value;

	cout << msg;
	cin >> value;

	return value;
}

Faculty* ioHandler::insertFaculty()
{
	// ID
	string id = getString(" ID : ");
	// 성명
	string name = getString(" 성명 : ");
	// 소속학과
	string department = getString(" 소속학과 : ");
	// 전공분야
	int major = getInteger(" 전공분야 : ");
	// 최종학위
	string degree = getString(" 최종학위 : ");

	Faculty* f = new Faculty(id, name, department, major, degree);

	return f;
}

Staff* ioHandler::insertStaff()
{
	// ID
	string id = getString(" ID : ");
	// 성명
	string name = getString(" 성명 : ");
	// 소속부서
	string department = getString(" 소속부서 : ");
	// 직급
	int rank = getInteger(" 직급: ");
	// 담당업무
	string duty = getString(" 담당업무 : ");

	Staff* s = new Staff(id, name, department, rank, duty);

	return s;
}

Undergraduate* ioHandler::insertUndergraduate()
{
	// ID
	string id = getString(" ID : ");
	// 성명
	string name = getString(" 성명 : ");
	// 소속학과
	string department = getString(" 소속학과 : ");
	// 학년
	int grade = getInteger(" 학년 : ");
	// 지도교수
	string advisor = getString(" 지도교수 : ");

	Undergraduate* u = new Undergraduate(id, name, department, grade, advisor);

	return u;
}

Graduate* ioHandler::insertGraduate()
{
	// ID
	string id = getString(" ID : ");
	// 성명
	string name = getString(" 성명 : ");
	// 소속학과
	string department = getString(" 소속학과 : ");
	// 학위과정
	string degree = getString(" 학위과정 : ");
	// 전공분야
	int major = getInteger(" 전공분야 : ");
	// 지도교수
	string advisor = getString(" 지도교수 : ");

	Graduate* g = new Graduate(id, name, department, degree, major, advisor);

	return g;
}

Member* ioHandler::getMember(char member_type)
{
	if (member_type == 'F')
	{
		// Faculty
		Member* mp = insertFaculty();

		return mp;
	}
	else if (member_type == 'S')
	{
		// Staff
		Member* mp = insertStaff();

		return mp;
	}
	else if (member_type == 'U')
	{
		// Undergraduate
		Member* mp = insertUndergraduate();

		return mp;
	}
	else if (member_type == 'G')
	{
		// Graduate
		Member* mp = insertGraduate();

		return mp;
	}
}

char ioHandler::insertMemberType()
{
	char member_type;

	while (1)
	{
		cout << endl;
		cout << "(F:교수, S:직원, U:학부생, G:대학원생) -> ";
		cin >> member_type;

		if (member_type == 'F' || member_type == 'S' || member_type == 'U' || member_type == 'G')
		{
			return member_type;
		}
		else
		{
			putString(" 잘못 입력하셨습니다 ");
		}
	}
}