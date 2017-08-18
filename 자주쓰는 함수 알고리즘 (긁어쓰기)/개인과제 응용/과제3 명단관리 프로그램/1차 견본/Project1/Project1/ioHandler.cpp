#include "ioHandler.h"

void ioHandler::getMenu()
{
	cout << "------ 명단관리 프로그램 ------" << endl;
	cout << "------ 1. 명단 정보 등록 ------" << endl;
	cout << "------ 2. 명단 정보 삭제 ------" << endl;
	cout << "------ 3. 명단 정보 수정 ------" << endl;
	cout << "------ 4. 명단 정보 출력 ------" << endl;
	cout << "------ 5. 프로그램 종료  ------" << endl;
	cout << "-------------------------------" << endl;
}

Faculty ioHandler::insertFaculty()
{
	string id = getString(" ID : ");
	string name = getString(" 이름 : ");
	string department = getString(" 소속학과 : ");
	int major = getInteger(" 전공분야 : ");
	int degree = getInteger(" 최종학위 : ");

	Faculty f(id, name, department, 1, major, degree);
	return f;
}

Staff ioHandler::insertStaff()
{
	string id = getString(" ID : ");
	string name = getString(" 이름 : ");
	string department = getString(" 소속부서 : ");
	int rank = getInteger(" 직급 : ");
	string duty = getString(" 담당업무 : ");

	Staff s(id, name, department, 2, rank, duty);
	return s;
}

Undergraduate ioHandler::insertUndergraduate()
{
	string id = getString(" ID : ");
	string name = getString(" 이름 : ");
	string department = getString(" 소속학과 : ");
	int grade = getInteger(" 학년 : ");
	string advisor = getString(" 지도교수 : ");

	Undergraduate u(id, name, department, 3, grade, advisor);
	return u;
}

Graduate ioHandler::insertGraduate()
{
	string id = getString(" ID : ");
	string name = getString(" 이름 : ");
	string department = getString(" 소속학과 : ");
	int degree = getInteger(" 학위과정 : ");
	int major = getInteger(" 전공분야 : ");
	string advisor = getString(" 지도교수 : ");

	Graduate g(id, name, department, 4, degree, major, advisor);
	return g;
}

void ioHandler::getInsertMenu()
{
	cout << "1. 교수" << endl;
	cout << "2. 직원" << endl;
	cout << "3. 학부생" << endl;
	cout << "4. 대학원생" << endl;
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

void ioHandler::printFaculty(Member& m_list)
{
	Faculty f;

	cout << " ID : " << m_list.getId() << endl;
	cout << " 성명 : " << m_list.getName() << endl;
	cout << " 부서 : " << m_list.getDepartment() << endl;
	cout << " 전공분야 : " << f.getMajor() << endl;
	cout << " 최종학위 : " << f.getDegree() << endl;
}

void ioHandler::printStaff()
{

}

void ioHandler::printUndergraduate()
{

}

void ioHandler::printGraduate()
{

}