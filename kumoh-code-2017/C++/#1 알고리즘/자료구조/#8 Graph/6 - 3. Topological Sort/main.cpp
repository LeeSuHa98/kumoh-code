#include "IoHandler.h"
#include "TaskManager.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "SetsGraph.h"
#include "TopologicalSortGraph.h"
#include "MinimumSpanningTree.h"

int main()
{
	IoHandler ioh;
	MatrixGraph mg;
	ListGraph lg;
	SetsGraph sg;
	TopologicalSortGraph tg;
	MinimumSpanningTree mt;
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
			tm.minimumCostSpanningTree(sg, mt);
			break;
		case 't':	// ��������
		case 'T':
			tm.topologicalSort(tg);
			break;
		case 'q':	// ����
		case 'Q':
			exit(1);
		}

	}

	system("pause");
	return 0;
}