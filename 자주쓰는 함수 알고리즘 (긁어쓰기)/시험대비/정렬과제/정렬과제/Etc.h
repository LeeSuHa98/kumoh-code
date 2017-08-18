#pragma once
#include "std.h"
template <class T>

class Etc
{
public:
	void getSort(T *arr, const int count)
	{
		clock_t begin;
		clock_t end;

		begin = clock();

		std::sort(arr, arr + count);

		end = clock();

		cout << "Std::Sort(" << count << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

	}
};