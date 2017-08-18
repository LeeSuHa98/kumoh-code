#include "MemberList.h"
#include "ioHandler.h"

int MemberList::findMember(string id)
{
	for (int i = 0; i < count; i++)
	{
		if (id == member_list[i].getId())
		{
			return i;
		}
	}
}

void MemberList::insertMember()
{
	ioHandler ioh;

	cout << " ��� ������ ����մϴ� " << endl;
	ioh.getInsertMenu();
	int select;

	cout << "select ->";
	cin >> select;

	switch (select)
	{
	case 1:
		cout << " ������ ����� ����մϴ� " << endl;
		member_list[count++] = Faculty(ioh.insertFaculty());
		break;

	case 2:
		cout << " ������ ����� ����մϴ� " << endl;
		ioh.insertStaff();
		break;

	case 3:
		cout << " �кλ��� ����� ����մϴ� " << endl;
		ioh.insertUndergraduate();
		break;

	case 4:
		cout << " ���п����� ����� ����մϴ� " << endl;
		ioh.insertGraduate();
		break;

	default:
		cout << "�߸����Է�" << endl;
		break;
	}
}

void MemberList::deleteMember()
{
	cout << " ��� ������ �����մϴ� " << endl;
}

void MemberList::updateMember()
{
	cout << " ��� ������ �����մϴ� " << endl;
}

void MemberList::displayMember()
{
	ioHandler ioh;

	cout << " ��� ������ ����մϴ� " << endl;

	for (int i = 0; i < count; i++)
	{
		if (member_list[i].getMemberType() == 1)
		{
			ioh.printFaculty(getMemberList(i));
		}
	/*	else if (member_list[i].getMemberType() == 2)
		{
			ioh.insertStaff(getMemberList(i));
		}
		else if (member_list[i].getMemberType() == 3)
		{
			ioh.insertGraduate(getMemberList(i));
		}
		else if (member_list[i].getMemberType() == 4)
		{
			ioh.insertUndergraduate(getMemberList(i));
		}*/
		else
		{
			cout << " �߸� �Է� �ϼ̽��ϴ� " << endl;
		}
	}
}