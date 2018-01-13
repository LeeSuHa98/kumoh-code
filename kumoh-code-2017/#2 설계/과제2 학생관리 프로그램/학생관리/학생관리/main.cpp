#include <iostream>
#include "Student.h"
#include "StudentList.h"
#include "TaskManager.h"
#include "ioHandler.h"

using namespace std;

int main()
{
	StudentList s_list;
	TaskManager tm;
	ioHandler ioh;

	while (true)
	{
		// �޴�
		int menu = ioh.getMenu();
		if (menu == EXIT) break;

		switch (menu)
		{
		case REGISTER :
			// �л� ���
			tm.registerStudent(s_list);
			break;
		case UNREGISTER :
			// �л� ����
			tm.unregisterStudent(s_list);
			break;
		case CHANGE :
			// �л� ����
			tm.changeStudent(s_list);
			break;
		case DISPLAY :
			// �л� ���
			tm.displayStudent(s_list);
			break;
		case EXIT :
			// ���α׷� ����
			exit(1);
			break;
		default:
			// ����ó��
			cout << " �߸� �Է��ϼ̽��ϴ� " << endl;
			return 0;
		}
	}
}