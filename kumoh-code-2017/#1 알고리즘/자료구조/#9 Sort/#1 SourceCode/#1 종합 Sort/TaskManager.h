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
	// �ʱ� ������ (����)
	T* initData = new T[numOfData];
	DataHandler dg;
	dg.generateData(initData, numOfData);

	FileHandler fh;
	IoHandler ioh;
	string dataOrder;

	// DataOrder�� ���� �ʱ� ������ ����
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
	fh.saveFile<T>(initData, numOfData, type + dataOrder + "���� ��.txt");

	// ������ ������
	T* sortData = new T[numOfData];
	Chain<T> c;

	time_t start, end;								//����, ���� �ð�
	double sortTime;								//���Ŀ� �ɸ� �ð�

	//int minRange;
	//int maxRange;

	ioh.getTypeMenu(type);
	//cout << "�ּ� ���� : ";
	//cin >> minRange;
	//cout << "�ִ� ���� : ";
	//cin >> maxRange;

	for (int i = per; i <= numOfData; i += per)
	{
		int currNumOfData = i;

		for (int j = 0; j <= 12; ++j)
		{
			cout << j << "��° �Լ������� ������" << endl;

			// ����������Ľ� ������ ü��
			if (j == 2)
			{
				for (int k = 0; k < currNumOfData; ++k)
				{
					c.insertNode(initData[k]);
				}
			}
			else
			{
				copy(initData, sortData, currNumOfData);	// ���� �� ������ ����
			}

			string sortName = "";

			// ���� ���� 
			start = clock();

			switch (j)
			{
			case 0:
				sortName = "[0]��������";
				insertionSort(sortData, currNumOfData);
				// cout << sortName;
				break;
			case 1:
				sortName = "[1]�̿���������";
				binaryInsertionSort(sortData, currNumOfData);
				break;
			case 2:
				sortName = "[2]�����������";
				c.insertionSort();
				break;
			case 3:
				sortName = "[3]������";
				quickSort(sortData, 0, currNumOfData -1);
				break;
			case 4:
				sortName = "[4]median of three ������";
				threeMedianRecursiveQuickSort(sortData, 0, currNumOfData - 1);
				break;
			case 5:
				sortName = "[5]median of three ������(�ݺ�)";
				threeMedianNonRecursiveQuickSort(sortData, 0, currNumOfData - 1);
				break;
			case 6:
				sortName = "[6]���̺귯��������";
				stdQuickSort(sortData, currNumOfData);
				break;
			case 7:
				sortName = "[7]����պ�����";
				recursiveMergeSort(sortData, currNumOfData);
				break;
			case 8:
				sortName = "[8]�ݺ��պ�����";
				iterativeMergeSort(sortData, currNumOfData);
				break;
			case 9:
				sortName = "[9]�ڿ��պ�����";
				naturalMergeSort(sortData, currNumOfData);
				break;
			case 10:
				sortName = "[10]������";
				heapSort(sortData, currNumOfData);
				break;
			case 11:
				sortName = "[11]��������";
				bubbleSort(sortData, currNumOfData);
				break;
			case 12:
				sortName = "[12]��������";
				selectionSort(sortData, currNumOfData);
				break;
			}

			// ���� ��
			end = clock();
			sortTime = (double)(end - start) / (double)CLOCKS_PER_SEC;
			char b[256];
			sprintf_s(b, "%.4lf", sortTime);	// �Ϸ��� ���� �� ���� ������ �����ϰ� buffer�� ����, ���� null ���ڸ� �����ϰ� buffer�� ����� ����Ʈ ���� ��ȯ
			string sortTimeStr = b;

			char d[256];
			_itoa_s(currNumOfData, d, 10);	// ���ڿ��� ������ ��ȯ
			string currNumOfDataStr = d;

			if (currNumOfData == numOfData)
			{
				if (j == 2)
				{
					fh.saveFile<T>(c, currNumOfData, currNumOfDataStr + "_" + dataOrder + "_" + type + "_" + sortName + "���( " + sortTimeStr + " ).txt");
				}
				else if (type == "String")
				{
					fh.saveFile(sortData, currNumOfData, currNumOfDataStr + "_" + dataOrder + "_" + type + "_" + sortName + "���( " + sortTimeStr + " ).txt");
				}
				else
				{
					fh.saveFile<T>(sortData, currNumOfData, currNumOfDataStr + "_" + dataOrder + "_" + type + "_" + sortName + "���( " + sortTimeStr + " ).txt");
				}
			}
		}
	}
}