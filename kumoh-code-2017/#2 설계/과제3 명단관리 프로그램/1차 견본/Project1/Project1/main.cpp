#include <iostream>
#include "Member.h"
#include "MemberList.h"

using namespace std;

int main()
{
	MemberList m_list;
	
	while (true)
	{
		// �޴�
		cout << "------ ��ܰ��� ���α׷� ------" << endl;
		cout << "------ 1. ��� ���� ��� ------" << endl;
		cout << "------ 2. ��� ���� ���� ------" << endl;
		cout << "------ 3. ��� ���� ���� ------" << endl;
		cout << "------ 4. ��� ���� ��� ------" << endl;
		cout << "------ 5. ���α׷� ����  ------" << endl;
		cout << "-------------------------------" << endl;

		int select;
		cin >> select;

		// ����
		switch (select)
		{
		case 1:
			// ���
			m_list.insertMember();
			break;
		case 2:
			// ����
			m_list.deleteMember();
			break;
		case 3:
			// ����
			m_list.updateMember();
			break;
		case 4:
			// ���
			m_list.displayMember();
			break;
		case 5:
			// ���α׷� ����
			exit(1);
		default:
			cout << " �߸� �Է��ϼ̽��ϴ� " << endl;
			return 0;
		}
	}
}