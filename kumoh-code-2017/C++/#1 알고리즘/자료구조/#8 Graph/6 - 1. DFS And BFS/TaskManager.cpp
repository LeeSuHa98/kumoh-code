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