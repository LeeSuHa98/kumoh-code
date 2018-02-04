/* ���� ���͵� ���� #1
�л� �������� ���α׷�
�̸� : �տ��
�й� : 20120691
*/

#include "PersonList.h"
#include "ioHandler.h"
#include "TaskManager.h"

int main()
{
	PersonList p_list;
	ioHandler ioh;
	TaskManager tm;

	while (1)
	{
		// �޴�
		int menu = ioh.getMenu();
		if (menu == EXIT) break; // ���α׷� ����

		switch (menu)
		{
		case INSERT:
			// ���
			tm.registerPerson(p_list);
			break;
		case UNREGISTER:
			// ����
			tm.unregisterPerson(p_list);
			break;
		case DISPLAY:
			// ���
			tm.displayPerson(p_list);
			break;
		case EXIT:
			// ����
			return 0;
		}
	}
}