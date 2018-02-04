#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>

using namespace std;

void load(string fileName, int* arr);
void save(string fileName, int* arr);
int compare(const void *a, const void  *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}

int main()
{
	int arr[50000]; // ������ ���� 5����

	load("QSortData.txt", arr);

	clock_t start, end;

	start = clock();
	
	qsort(arr, 50000, sizeof(int), compare);

	end = clock();

	double sortTime = (double)(end - start) / CLOCKS_PER_SEC;
	char b[256];
	sprintf_s(b, "%.4lf", sortTime);	// �Ϸ��� ���� �� ���� ������ �����ϰ� buffer�� ����, ���� null ���ڸ� �����ϰ� buffer�� ����� ����Ʈ ���� ��ȯ
	string sortTimeStr = b;

	string sortName = "QSortData_C++.txt";
	
	save(sortName + " ���( " + sortTimeStr + " ).txt", arr);

	return 0;
}

void load(string fileName, int* arr)
{
	ifstream fin;

	fin.open(fileName);
	if (fin.fail())
	{
		cout << "�ش� ������ ���� ���߽��ϴ�." << endl;
		return;
	}

	for (int i = 0; i < 50000; i++)
	{
		fin >> arr[i];
	}
	fin.close();

	int target = 0;
}
void save(string fileName, int* arr)
{
	ofstream fout;

	fout.open(fileName);

	for (int i = 0; i < 50000; i++)
	{
		fout << arr[i] << endl;
	}
	fout.close();
}