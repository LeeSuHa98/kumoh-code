#pragma once
#include "common.h"
#include "Chain.h"

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}

	template <class T>
	void saveFile(T* a, int numOfData, string fileName);
	void saveFile(string* a, int numOfData, string fileName);

	template <class T>
	void saveFile(Chain<T>& c, int numOfData, string fileName);
};

template <class T>
void FileHandler::saveFile(T* a, int numOfData, string fileName)
{
	ofstream fout;

	fout.open(fileName);

	if (fout.fail())
	{
		cout << "파일을 찾을수 없습니다.";
		return;
	}

	for (int i = 0; i < numOfData; ++i)
	{
		fout << a[i];
		if (i != numOfData - 1)
		{
			fout << endl;
		}
	}

	fout.close();
}

template<class T>
void FileHandler::saveFile(Chain<T>& c, int numOfData, string fileName)
{
	ofstream fout;

	fout.open(fileName);

	if (fout.fail())
	{
		cout << "파일을 찾을수 없습니다.";
		return;
	}

	T a;
	c.setCurrToFirst();

	for (int i = 0; i < numOfData; ++i)
	{
		a = c.getCurrData();
		fout << a;
		if (i != numOfData - 1)
		{
			fout << endl;
		}
		c.setCurrToNext();
	}

	fout.close();
}