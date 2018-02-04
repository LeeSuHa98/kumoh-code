#include "QuickSort.h"
#include "IoHandler.h"
#include "FileHandler.h"
#include <ctime>

int main()
{
	IoHandler ioh;
	FileHandler fh;

	ioh.putString("정렬할 수의 개수 (정적) : ");
	int size;
	cin >> size;

	int* arr = nullptr;

	arr = new int[size + 1];
	fh.loadFile("QSortData.txt", arr);

	QuickSort<int> qs;

	clock_t start, end;

	start = clock();

	qs.threeMedianRecursiveQuickSort(arr, 0, size - 1);

	end = clock();

	double sortTime = (double)(end - start) / CLOCKS_PER_SEC;

	char b[256];
	sprintf_s(b, "%.4lf", sortTime);	// 일련의 문자 및 값의 서식을 지정하고 buffer에 저장, 종료 null 문자를 제외하고 buffer에 저장된 바이트 수를 반환
	string sortTimeStr = b;

	string sortName = "QSortData_C++.txt";
	fh.saveFile(sortName + " 결과( " + sortTimeStr + " ).txt", arr, size);

	delete[] arr;

	system("pause");

	return 0;
}