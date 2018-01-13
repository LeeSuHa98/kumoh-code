#include "IoHandler.h"
#include "TaskManager.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

int main()
{
	IoHandler ioh;
	MatrixGraph mg;
	ListGraph lg;
	TaskManager tm;

	while (1)
	{
		char menu = ioh.getMenu();

		switch (menu)
		{
		case 's': // Ž��
		case 'S':
			tm.searchGraph(mg, lg);
			break;
		case 'm':	// �ּҺ�� ����Ʈ��
		case 'M':
			break;
		case 't':	// ��������
		case 'T':
			break;
		case 'q':	// ����
		case 'Q':
			exit(1);
		}

	}

	system("pause");
	return 0;
}