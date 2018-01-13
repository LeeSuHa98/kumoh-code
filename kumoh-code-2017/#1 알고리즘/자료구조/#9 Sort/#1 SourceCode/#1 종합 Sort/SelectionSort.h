#pragma once
#include "common.h"

template <class T>
void selectionSort(T* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[k] > a[j])
			{
				k = j;
			}
		}
		swap(a[i], a[k]);
	}
}