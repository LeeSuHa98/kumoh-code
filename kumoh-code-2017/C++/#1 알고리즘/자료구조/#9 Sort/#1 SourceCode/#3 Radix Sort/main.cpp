#include "RadixSort.h"
#include "MergeSort.h"
#include "IoHandler.h"
#include "FileHandler.h"
#include <ctime>

int main()
{
	IoHandler ioh;
	FileHandler fh;
	RadixSort rs;
	MergeSort ms;


	int* arr = nullptr;
	string* hexArr = nullptr;

	arr = new int[50000 + 1];
	hexArr = new string[50000 + 1];
	fh.loadFile("RadixSortData.txt", arr);
	// �Ű� ���� ( �迭, �迭 size, �ִ� �ڸ���, ���( ex: 16 ) )
	rs.getHex(hexArr, arr);

	string sortName = "";

	clock_t start, end;
	double sortTime;

	start = clock();	// ���� ����

	while (1)
	{
		int select = ioh.getMenu();
		if (select == 1)
		{
			// modulo ����(%) ���� 16���� LSB ���� ��� �����ϴ� radix sort
			sortName = "hexademicalRadixSort.txt";
			rs.hexademicalRadixSort(hexArr, 50000, 5, 16);
			break;
		}
		else if (select == 2)
		{
			//masking(&)�� shift ����(>>)�������� 16���� LSB���� ��� �����ϴ� radix sort
			sortName = "maskingAndShiftRadixSort.txt";
			rs.maskingAndShiftRadixSort(arr, 50000, 5, 16);
			break;
		}
		else if (select == 3)
		{
			//modulo ����(%) ���� 10���� LSB ���� ��� �����ϴ� radix sort
			sortName = "demicalRadixSort.txt";
			rs.demicalRadixSort(arr, 50000, 5, 10);
			break;
		}
		else if (select == 4)
		{
			//4) ������ ���� sort �� random int�� ���ؼ� ���� ���� ȿ���� �� ��
			sortName = "iterativeMergeSort.txt";
			ms.iterativeMergeSort(arr, 50000);
			break;
		}
		else
		{
			exit(1);
		}
	}

	end = clock();

	sortTime = (double)(end - start) / CLOCKS_PER_SEC;

	rs.getDec(hexArr, arr);

	char b[256];
	sprintf_s(b, "%.4lf", sortTime);	// �Ϸ��� ���� �� ���� ������ �����ϰ� buffer�� ����, ���� null ���ڸ� �����ϰ� buffer�� ����� ����Ʈ ���� ��ȯ
	string sortTimeStr = b;

	fh.saveFile(sortName + " ���( " + sortTimeStr + " ).txt", arr, 50000);

	delete[] arr;
	delete[] hexArr;

	system("pause");

	return 0;
}