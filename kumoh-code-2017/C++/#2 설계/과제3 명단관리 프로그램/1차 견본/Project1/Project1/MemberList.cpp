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

	cout << " 명단 정보를 등록합니다 " << endl;
	ioh.getInsertMenu();
	int select;

	cout << "select ->";
	cin >> select;

	switch (select)
	{
	case 1:
		cout << " 교수의 명단을 등록합니다 " << endl;
		member_list[count++] = Faculty(ioh.insertFaculty());
		break;

	case 2:
		cout << " 직원의 명단을 등록합니다 " << endl;
		ioh.insertStaff();
		break;

	case 3:
		cout << " 학부생의 명단을 등록합니다 " << endl;
		ioh.insertUndergraduate();
		break;

	case 4:
		cout << " 대학원생의 명단을 등록합니다 " << endl;
		ioh.insertGraduate();
		break;

	default:
		cout << "잘못된입력" << endl;
		break;
	}
}

void MemberList::deleteMember()
{
	cout << " 명단 정보를 삭제합니다 " << endl;
}

void MemberList::updateMember()
{
	cout << " 명단 정보를 수정합니다 " << endl;
}

void MemberList::displayMember()
{
	ioHandler ioh;

	cout << " 명단 정보를 출력합니다 " << endl;

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
			cout << " 잘못 입력 하셨습니다 " << endl;
		}
	}
}