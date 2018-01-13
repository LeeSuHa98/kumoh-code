#include "QuickSort.h"
#include "IoHandler.h"
#include "FileHandler.h"
#include <ctime>

int main()
{
	IoHandler ioh;
	FileHandler fh;

	ioh.putString("������ ���� ���� (����) : ");
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
	sprintf_s(b, "%.4lf", sortTime);	// �Ϸ��� ���� �� ���� ������ �����ϰ� buffer�� ����, ���� null ���ڸ� �����ϰ� buffer�� ����� ����Ʈ ���� ��ȯ
	string sortTimeStr = b;

	string sortName = "QSortData_C++.txt";
	fh.saveFile(sortName + " ���( " + sortTimeStr + " ).txt", arr, size);

	delete[] arr;

	system("pause");

	return 0;
}