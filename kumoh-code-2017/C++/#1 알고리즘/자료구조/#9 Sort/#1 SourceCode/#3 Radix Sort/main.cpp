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
	// 매개 변수 ( 배열, 배열 size, 최대 자리수, 기수( ex: 16 ) )
	rs.getHex(hexArr, arr);

	string sortName = "";

	clock_t start, end;
	double sortTime;

	start = clock();	// 정렬 시작

	while (1)
	{
		int select = ioh.getMenu();
		if (select == 1)
		{
			// modulo 연산(%) 으로 16진수 LSB 값을 얻어 정렬하는 radix sort
			sortName = "hexademicalRadixSort.txt";
			rs.hexademicalRadixSort(hexArr, 50000, 5, 16);
			break;
		}
		else if (select == 2)
		{
			//masking(&)과 shift 연산(>>)연산으로 16진수 LSB값을 얻어 정렬하는 radix sort
			sortName = "maskingAndShiftRadixSort.txt";
			rs.maskingAndShiftRadixSort(arr, 50000, 5, 16);
			break;
		}
		else if (select == 3)
		{
			//modulo 연산(%) 으로 10진수 LSB 값을 얻어 정렬하는 radix sort
			sortName = "demicalRadixSort.txt";
			rs.demicalRadixSort(arr, 50000, 5, 10);
			break;
		}
		else if (select == 4)
		{
			//4) 팀에서 만든 sort 중 random int에 대해서 제일 좋은 효율을 낸 것
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
	sprintf_s(b, "%.4lf", sortTime);	// 일련의 문자 및 값의 서식을 지정하고 buffer에 저장, 종료 null 문자를 제외하고 buffer에 저장된 바이트 수를 반환
	string sortTimeStr = b;

	fh.saveFile(sortName + " 결과( " + sortTimeStr + " ).txt", arr, 50000);

	delete[] arr;
	delete[] hexArr;

	system("pause");

	return 0;
}