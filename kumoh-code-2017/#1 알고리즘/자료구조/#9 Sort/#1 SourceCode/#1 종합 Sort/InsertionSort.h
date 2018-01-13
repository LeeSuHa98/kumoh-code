#pragma once
#include "common.h"

template <class T>
void insertionSort(T* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		T e = a[i];
		int j;
		for (j = i - 1; j >= 0 && e < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = e;
	}
}


template <class T>
int binarySearch(T* a, int low, int high, T key)
{
	int mid;

	if (low == high)
	{
		return low;
	}

	mid = low + ((high - low) / 2);

	if (key > a[mid])
	{
		return binarySearch(a, mid + 1, high, key);
	}
	else
	{
		return binarySearch(a, low, mid, key);
	}
	return mid;
}


template <class T>
void binaryInsertionSort(T* a, int n)
{
	int i, j, find;
	T temp;

	for (i = 1; i<n; i++)
	{
		find = binarySearch(a, 0, i, a[i]);
		if (find < i)
		{
			temp = a[i];
			for (j = i - 1; j >= find; j--)
			{
				a[j + 1] = a[j];
			}
			a[find] = temp;
		}
	}
}
