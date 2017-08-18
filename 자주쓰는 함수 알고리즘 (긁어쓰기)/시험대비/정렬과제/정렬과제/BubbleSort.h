#pragma once
#include "std.h"
template <class T>

class BubbleSort
{
public:
	BubbleSort(void) {}

	void getSort(T *arr, const int count)
	{
		result(arr, count);
	}

	void result(T *arr, int count)
	{
		T *data = new T[count];

		for (int i = 0; i < count; i++)
			data[i] = arr[i];
		clock_t begin;
		clock_t end;
		begin = clock();
		for (int i = 0; i < count; i++)
		{
			int small = i;
			for (int k = i + 1; k < count; k++)
			{
				if (data[small] > data[k])
				{
					T temp = data[small];
					data[small] = data[k];
					data[k] = temp;
				}
			}
		}
		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "Bubble Sort(" << count << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;

		delete[] data;
	}
};