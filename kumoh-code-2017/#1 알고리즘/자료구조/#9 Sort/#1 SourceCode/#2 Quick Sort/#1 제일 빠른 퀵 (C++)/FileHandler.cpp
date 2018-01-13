#include "FileHandler.h"

void FileHandler::loadFile(string fileName, int*& arr)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (!fin)
	{
		cout << "열리지 않음" << endl;
		exit(1);
	}

	int value = 0;

	int insert = 0;
	while (!fin.eof())
	{
		fin >> value;
		arr[insert++] = value;
	}
	fin.close();

	return;
}

void FileHandler::saveFile(string fileName, int*& arr, int size)
{
	ofstream fout;

	fout.open(fileName);

	if (fout.fail())
	{
		cout << "파일을 찾을 수 없습니다.";
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		fout << arr[i];
		if (i != size - 1)
		{
			fout << endl;
		}
	}

	fout.close();
}