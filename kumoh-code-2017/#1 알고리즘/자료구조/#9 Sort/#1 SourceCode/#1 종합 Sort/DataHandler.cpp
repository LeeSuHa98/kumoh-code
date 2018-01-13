#include "DataHandler.h"

void DataHandler::generateData(int* a, int numOfData)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		a[i] = rand();
	}
}

void DataHandler::generateData(double* a, int numOfData)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		a[i] = (double)rand() * 1000 / rand();
	}
}

void DataHandler::generateData(string* a, int numOfData)
{
	const char c[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
		, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
		, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		int length = rand() % 4 + 1;
		for (int j = 0; j < length; ++j)
		{
			a[i] += c[rand() % 62];
		}
	}
}

void DataHandler::generateData(Student* a, int numOfData)
{
	srand((unsigned)time(NULL));
	int kor;
	int math;
	int eng;
	for (int i = 0; i < numOfData; ++i)
	{
		kor = (double)rand() * 1000 / rand();
		math = (double)rand() * 1000 / rand();
		eng = (double)rand() * 1000 / rand();
		Student s(kor, math, eng);
		a[i] = s;
	}
}