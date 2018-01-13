#include "ioHandler.h"

int ioHandler::getMenu()
{
	cout << "------ ��ܰ��� ���α׷� ------" << endl;
	cout << "------ 1. ��� ���� ��� ------" << endl;
	cout << "------ 2. ��� ���� ���� ------" << endl;
	cout << "------ 3. ��� ���� ���� ------" << endl;
	cout << "------ 4. ��� ���� ��� ------" << endl;
	cout << "------ 5. ���α׷� ����  ------" << endl;

	int menu = getInteger(" ���� : ");

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
	// ����
	string name = getString(" ���� : ");
	// �Ҽ��а�
	string department = getString(" �Ҽ��а� : ");
	// �����о�
	int major = getInteger(" �����о� : ");
	// ��������
	string degree = getString(" �������� : ");

	Faculty* f = new Faculty(id, name, department, major, degree);

	return f;
}

Staff* ioHandler::insertStaff()
{
	// ID
	string id = getString(" ID : ");
	// ����
	string name = getString(" ���� : ");
	// �ҼӺμ�
	string department = getString(" �ҼӺμ� : ");
	// ����
	int rank = getInteger(" ����: ");
	// ������
	string duty = getString(" ������ : ");

	Staff* s = new Staff(id, name, department, rank, duty);

	return s;
}

Undergraduate* ioHandler::insertUndergraduate()
{
	// ID
	string id = getString(" ID : ");
	// ����
	string name = getString(" ���� : ");
	// �Ҽ��а�
	string department = getString(" �Ҽ��а� : ");
	// �г�
	int grade = getInteger(" �г� : ");
	// ��������
	string advisor = getString(" �������� : ");

	Undergraduate* u = new Undergraduate(id, name, department, grade, advisor);

	return u;
}

Graduate* ioHandler::insertGraduate()
{
	// ID
	string id = getString(" ID : ");
	// ����
	string name = getString(" ���� : ");
	// �Ҽ��а�
	string department = getString(" �Ҽ��а� : ");
	// ��������
	string degree = getString(" �������� : ");
	// �����о�
	int major = getInteger(" �����о� : ");
	// ��������
	string advisor = getString(" �������� : ");

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
		cout << "(F:����, S:����, U:�кλ�, G:���п���) -> ";
		cin >> member_type;

		if (member_type == 'F' || member_type == 'S' || member_type == 'U' || member_type == 'G')
		{
			return member_type;
		}
		else
		{
			putString(" �߸� �Է��ϼ̽��ϴ� ");
		}
	}
}