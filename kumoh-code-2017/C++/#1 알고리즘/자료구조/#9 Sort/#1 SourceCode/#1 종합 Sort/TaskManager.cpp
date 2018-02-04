#include "TaskManager.h"

void TaskManager::registerSortData(int select)
{
	int num;
	int per;

	switch (select)
	{
	case 'r':
	case 'R':
		cout << "num : ";
		cin >> num;
		cout << "per : ";
		cin >> per;
		//checkSortTime<Student>(num, per, RANDOM, "Student");
		//checkSortTime<int>(num, per, RANDOM, "Integer");
		//checkSortTime<double>(num, per, RANDOM, "Double");
		checkSortTime<string>(num, per, RANDOM, "String");
		break;
	case 'i':
	case 'I':
		cout << "num : ";
		cin >> num;
		cout << "per : ";
		cin >> per;
		checkSortTime<Student>(num, per, INCREASE, "Student");
		checkSortTime<int>(num, per, INCREASE, "Integer");
		checkSortTime<double>(num, per, INCREASE, "Double");
		//checkSortTime<string>(num, per, INCREASE, "String");
		break;
	case 'd':
	case 'D':
		cout << "num : ";
		cin >> num;
		cout << "per : ";
		cin >> per;
		checkSortTime<Student>(num, per, DECREASE, "Student");
		checkSortTime<int>(num, per, DECREASE, "Integer");
		checkSortTime<double>(num, per, DECREASE, "Double");
		//checkSortTime<string>(num, per, DECREASE, "String");
		break;
	case 'q':
	case 'Q':
		break;
	}
}