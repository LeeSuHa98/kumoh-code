#pragma once
#include "std.h"

template <class T>
class SelectionSort
{
public:
	SelectionSort(void) {}

	void getSort(T *arr, const int count)
	{
		result(arr, count);
	}

	void result(T* D, int count)
	{
		T *data = new T[count];
		for (int i = 0; i < count; i++)
			data[i] = D[i];

		clock_t begin;
		clock_t end;
		begin = clock();
		for (int i = 0; i < count; i++)
		{
			int small = i;
			for (int k = i + 1; k < count; k++)
			{
				if (data[small] > data[k])
					small = k;
			}
			T temp = data[small];
			data[small] = data[i];
			data[i] = temp;
		}

		end = clock();
		cout << "Selection Sort(" << count << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

		delete[] data;
	}
};
