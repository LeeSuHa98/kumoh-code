#include "ioHandler.h"

void ioHandler::getMenu()
{
	cout << "------ ��ܰ��� ���α׷� ------" << endl;
	cout << "------ 1. ��� ���� ��� ------" << endl;
	cout << "------ 2. ��� ���� ���� ------" << endl;
	cout << "------ 3. ��� ���� ���� ------" << endl;
	cout << "------ 4. ��� ���� ��� ------" << endl;
	cout << "------ 5. ���α׷� ����  ------" << endl;
	cout << "-------------------------------" << endl;
}

Faculty ioHandler::insertFaculty()
{
	string id = getString(" ID : ");
	string name = getString(" �̸� : ");
	string department = getString(" �Ҽ��а� : ");
	int major = getInteger(" �����о� : ");
	int degree = getInteger(" �������� : ");

	Faculty f(id, name, department, 1, major, degree);
	return f;
}

Staff ioHandler::insertStaff()
{
	string id = getString(" ID : ");
	string name = getString(" �̸� : ");
	string department = getString(" �ҼӺμ� : ");
	int rank = getInteger(" ���� : ");
	string duty = getString(" ������ : ");

	Staff s(id, name, department, 2, rank, duty);
	return s;
}

Undergraduate ioHandler::insertUndergraduate()
{
	string id = getString(" ID : ");
	string name = getString(" �̸� : ");
	string department = getString(" �Ҽ��а� : ");
	int grade = getInteger(" �г� : ");
	string advisor = getString(" �������� : ");

	Undergraduate u(id, name, department, 3, grade, advisor);
	return u;
}

Graduate ioHandler::insertGraduate()
{
	string id = getString(" ID : ");
	string name = getString(" �̸� : ");
	string department = getString(" �Ҽ��а� : ");
	int degree = getInteger(" �������� : ");
	int major = getInteger(" �����о� : ");
	string advisor = getString(" �������� : ");

	Graduate g(id, name, department, 4, degree, major, advisor);
	return g;
}

void ioHandler::getInsertMenu()
{
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. �кλ�" << endl;
	cout << "4. ���п���" << endl;
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
	cout << " ���� : " << m_list.getName() << endl;
	cout << " �μ� : " << m_list.getDepartment() << endl;
	cout << " �����о� : " << f.getMajor() << endl;
	cout << " �������� : " << f.getDegree() << endl;
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