#include "TaskManager.h"

void TaskManager::searchGraph(MatrixGraph& mg, ListGraph& lg)
{
	IoHandler ioh;

	char menu = ioh.getSearchGraphMenu();

	switch (menu)
	{
	case 'm':
	case 'M':
		mg.displayMatrix(mg);
		break;
	case 'l':
	case 'L':
		lg.displayList(lg);
		break;
	case 'q':
	case 'Q':
		break;
	}

	return;
}

void TaskManager::minimumCostSpanningTree(SetsGraph& sg, MinimumSpanningTree& mt)
{
	IoHandler ioh;
	string fileName = ioh.getString("무방향 가중치 그래프가 저장된 파일명을 입력하시오.(종료는 quit) : ");
	if (fileName == "quit")
	{
		exit(1);
	}

	FileHandler fh;
	fh.loadKruskal(fileName, sg, mt);
	mt.kruskalAlgorithm(sg);
}