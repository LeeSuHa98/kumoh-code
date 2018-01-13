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
	int arr[50000]; // 데이터 갯수 5만개

	load("QSortData.txt", arr);

	clock_t start, end;

	start = clock();
	
	qsort(arr, 50000, sizeof(int), compare);

	end = clock();

	double sortTime = (double)(end - start) / CLOCKS_PER_SEC;
	char b[256];
	sprintf_s(b, "%.4lf", sortTime);	// 일련의 문자 및 값의 서식을 지정하고 buffer에 저장, 종료 null 문자를 제외하고 buffer에 저장된 바이트 수를 반환
	string sortTimeStr = b;

	string sortName = "QSortData_C++.txt";
	
	save(sortName + " 결과( " + sortTimeStr + " ).txt", arr);

	return 0;
}

void load(string fileName, int* arr)
{
	ifstream fin;

	fin.open(fileName);
	if (fin.fail())
	{
		cout << "해당 파일을 열지 못했습니다." << endl;
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