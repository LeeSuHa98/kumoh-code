#pragma once
#include "std.h"
template <class T>

class HeapSort
{
public:
	HeapSort() {}

	void getSort(T *arr, const int count)
	{
		heapSort(arr, count);
	}

	void Adjust(T *list, const int root, const int num)
	{
		T e = list[root];

		int j = 0;
		for (j = 2 * root; j <= num; j *= 2)
		{
			if (j < num && list[j] < list[j + 1])
			{
				j++;
			}
			if (e >= list[j])
				break;
			list[j / 2] = list[j];
		}
		list[j / 2] = e;
	}
	void heapSort(T *arr, const int count)
	{
		clock_t begin;
		clock_t end;

		T* heap = new T[count + 1];

		for (int i = 0; i < count; i++)
			heap[i + 1] = arr[i];

		begin = clock();

		//비감소 순으로 정렬
		for (int i = count / 2; i >= 1; i--) //히프로 조정
		{
			Adjust(heap, i, count);
		}
		for (int i = count - 1; i >= 1; i--)
		{
			swap(heap[1], heap[i + 1]); //현히프의 처음과 마지막을 교환

			Adjust(heap, 1, i); //히프로 조정
		}

		end = clock();
		cout << "Heap Sort(" << count << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

		/*if (count == 1000)
		for (int i = 1; i < count+1; i++)
		{
		cout << heap[i] << " ";
		}*/


		delete[] heap;
	}

};
