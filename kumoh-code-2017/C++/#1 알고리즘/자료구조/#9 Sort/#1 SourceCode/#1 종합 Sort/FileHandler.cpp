#include "FileHandler.h"

void FileHandler::saveFile(string* a, int numOfData, string fileName)
{
	ofstream fout;

	fout.open(fileName);

	if (fout.fail())
	{
		cout << "파일을 찾을 수 없습니다.";
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
