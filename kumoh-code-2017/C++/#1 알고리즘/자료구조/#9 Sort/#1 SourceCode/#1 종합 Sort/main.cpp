#include "TaskManager.h"
#include "IoHandler.h"

int main()
{
	TaskManager tm;
	IoHandler ioh;

	while (1)
	{
		char select = ioh.getMenu();

		if (select == 'i' || select == 'I')
		{
			char type = ioh.getSortMenu();
			tm.registerSortData(type);
		}
		else if (select == 'q' || select == 'Q')
		{
			exit(1);
		}
	}

	system("pause");
}