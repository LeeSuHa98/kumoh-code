#include "Person.h"
#include "PersonList.h"

int main()
{
	PersonList p_list;

	while (1)
	{
		cout << "------ �������� ���α׷� ------" << endl;
		cout << "------ 1. ��� ���� ��� ------" << endl;
		cout << "------ 2. ��� ���� ���� ------" << endl;
		cout << "------ 3. ��� ���� ��� ------" << endl;
		cout << "------ 4. ���α׷� ����  ------" << endl;

		int select;
		cin >> select;

		switch (select)
		{
		case REGISTER:
			// ���
			p_list.inputPerson();
			break;
		case UNREGISTER:
			// ����
			p_list.deletePerson();
			break;
		case DISPLAY:
			// ���
			p_list.displayPerson();
			break;
		case EXIT:
			// ����
			return 0;
		}
	}
}