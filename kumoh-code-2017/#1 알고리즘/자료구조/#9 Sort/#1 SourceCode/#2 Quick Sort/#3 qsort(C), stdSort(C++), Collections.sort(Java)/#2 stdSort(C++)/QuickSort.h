#pragma once
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

template <class T>
class QuickSort
{
public:
	QuickSort<T>() {}
	~QuickSort<T>() {}

	void stdQuickSort(T*& arr, int size);
};

template <class T>
void QuickSort<T>::stdQuickSort(T*& arr, int size)
{
	std::sort(arr, arr + size);
	return;
}