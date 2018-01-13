#pragma once
#include "DataHandler.h"
#include "FileHandler.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "Chain.h"
#include "IoHandler.h"

class TaskManager
{
private:
	template <class T>
	void copy(T* initData, T* copyData, int numOfData);

public:
	TaskManager() {}
	~TaskManager() {}

	template<class T>
	void checkSortTime(int numOfData, int per, DataOrder order, string type);
	void registerSortData(int select);
};

template<class T>
void TaskManager::copy(T* initData, T* copyData, int numOfData)
{
	for (int i = 0; i < numOfData; ++i)
	{
		copyData[i] = initData[i];
	}
}

template<class T>
void TaskManager::checkSortTime(int numOfData, int per, DataOrder dOrder, string type)
{
	// 초기 데이터 (랜덤)
	T* initData = new T[numOfData];
	DataHandler dg;
	dg.generateData(initData, numOfData);

	FileHandler fh;
	IoHandler ioh;
	string dataOrder;

	// DataOrder에 따라 초기 데이터 설정
	switch (dOrder)
	{
	case RANDOM:
		dataOrder = "RANDOM";
		break;
	case INCREASE:
		dataOrder = "INCREASE";
		sort(initData, initData + numOfData);
		break;
	case DECREASE:
		dataOrder = "DECREASE";
		sort(initData, initData + numOfData, greater<T>());
		break;
	default:
		break;
	}
	fh.saveFile<T>(initData, numOfData, type + dataOrder + "정렬 전.txt");

	// 정렬할 데이터
	T* sortData = new T[numOfData];
	Chain<T> c;

	time_t start, end;								//시작, 종료 시간
	double sortTime;								//정렬에 걸린 시간

	//int minRange;
	//int maxRange;

	ioh.getTypeMenu(type);
	//cout << "최소 범위 : ";
	//cin >> minRange;
	//cout << "최대 범위 : ";
	//cin >> maxRange;

	for (int i = per; i <= numOfData; i += per)
	{
		int currNumOfData = i;

		for (int j = 0; j <= 12; ++j)
		{
			cout << j << "번째 함수에대해 정렬중" << endl;

			// 연결삽입정렬시 생성될 체인
			if (j == 2)
			{
				for (int k = 0; k < currNumOfData; ++k)
				{
					c.insertNode(initData[k]);
				}
			}
			else
			{
				copy(initData, sortData, currNumOfData);	// 정렬 할 데이터 복사
			}

			string sortName = "";

			// 정렬 시작 
			start = clock();

			switch (j)
			{
			case 0:
				sortName = "[0]삽입정렬";
				insertionSort(sortData, currNumOfData);
				// cout << sortName;
				break;
			case 1:
				sortName = "[1]이원삽입정렬";
				binaryInsertionSort(sortData, currNumOfData);
				break;
			case 2:
				sortName = "[2]연결삽입정렬";
				c.insertionSort();
				break;
			case 3:
				sortName = "[3]퀵정렬";
				quickSort(sortData, 0, currNumOfData -1);
				break;
			case 4:
				sortName = "[4]median of three 퀵정렬";
				threeMedianRecursiveQuickSort(sortData, 0, currNumOfData - 1);
				break;
			case 5:
				sortName = "[5]median of three 퀵정렬(반복)";
				threeMedianNonRecursiveQuickSort(sortData, 0, currNumOfData - 1);
				break;
			case 6:
				sortName = "[6]라이브러리퀵정렬";
				stdQuickSort(sortData, currNumOfData);
				break;
			case 7:
				sortName = "[7]재귀합병정렬";
				recursiveMergeSort(sortData, currNumOfData);
				break;
			case 8:
				sortName = "[8]반복합병정렬";
				iterativeMergeSort(sortData, currNumOfData);
				break;
			case 9:
				sortName = "[9]자연합병정렬";
				naturalMergeSort(sortData, currNumOfData);
				break;
			case 10:
				sortName = "[10]힙정렬";
				heapSort(sortData, currNumOfData);
				break;
			case 11:
				sortName = "[11]버블정렬";
				bubbleSort(sortData, currNumOfData);
				break;
			case 12:
				sortName = "[12]선택정렬";
				selectionSort(sortData, currNumOfData);
				break;
			}

			// 정렬 끝
			end = clock();
			sortTime = (double)(end - start) / (double)CLOCKS_PER_SEC;
			char b[256];
			sprintf_s(b, "%.4lf", sortTime);	// 일련의 문자 및 값의 서식을 지정하고 buffer에 저장, 종료 null 문자를 제외하고 buffer에 저장된 바이트 수를 반환
			string sortTimeStr = b;

			char d[256];
			_itoa_s(currNumOfData, d, 10);	// 문자열을 정수로 변환
			string currNumOfDataStr = d;

			if (currNumOfData == numOfData)
			{
				if (j == 2)
				{
					fh.saveFile<T>(c, currNumOfData, currNumOfDataStr + "_" + dataOrder + "_" + type + "_" + sortName + "결과( " + sortTimeStr + " ).txt");
				}
				else if (type == "String")
				{
					fh.saveFile(sortData, currNumOfData, currNumOfDataStr + "_" + dataOrder + "_" + type + "_" + sortName + "결과( " + sortTimeStr + " ).txt");
				}
				else
				{
					fh.saveFile<T>(sortData, currNumOfData, currNumOfDataStr + "_" + dataOrder + "_" + type + "_" + sortName + "결과( " + sortTimeStr + " ).txt");
				}
			}
		}
	}
}