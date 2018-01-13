#include "FileHandler.h"

void FileHandler::saveFile(string* a, int numOfData, string fileName)
{
	ofstream fout;

	fout.open(fileName);

	if (fout.fail())
	{
		cout << "������ ã�� �� �����ϴ�.";
		return;
	}

	for (int i = 0; i < numOfData; ++i)
	{
		fout << a[i].c_str();
		if (i != numOfData - 1)
		{
			fout << endl;
		}
	}

	fout.close();
}
