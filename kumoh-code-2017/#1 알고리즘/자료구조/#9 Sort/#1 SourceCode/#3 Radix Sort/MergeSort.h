#pragma once
#include "common.h"

class MergeSort
{
public:
	MergeSort() {}
	~MergeSort() {}

	template<class T>
	void merge(T* a, T* mergedList, int left, int mid, int right);
	template<class T>
	void iterativeMergeSort(T* a, int n);
};

template <class T>
void MergeSort::merge(T* a, T* mergedList, int left, int mid, int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
		{
			mergedList[k] = a[i];
			k++;
			i++;
		}
		else
		{
			mergedList[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		mergedList[k] = a[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		mergedList[k] = a[j];
		k++;
		j++;
	}

	for (i = left; i < k; i++)
	{
		a[i] = mergedList[i];
	}
}

template <class T>
void MergeSort::iterativeMergeSort(T* a, int n)
{
	T* mergedList = new T[n];

	int i, j;
	int left, mid, right;

	for (i = 1; i <= n; i *= 2)
	{
		for (j = 0; j + i < n; j += (2 * i))
		{
			left = j;
			mid = j + i - 1;
			right = mid + i;
			if (right >= n)
			{
				right = n - 1;
			}
			merge(a, mergedList, left, mid, right);
		}
	}

	if (n % (i / 2) != 0)
	{
		merge(a, mergedList, 0, ((n - 1) - (n % (i / 2))), n - 1);
	}

	delete[]mergedList;
}