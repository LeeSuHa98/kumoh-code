#pragma once
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

template <class T>
class QuickSort
{
private:
	int medianOfThree(T*& arr, int left, int right);
public:
	QuickSort<T>() {}
	~QuickSort<T>() {}

	void threeMedianRecursiveQuickSort(T*& arr, int left, int right);//두번째 퀵 소트

};

//three median 탐색
template <class T>
int QuickSort<T>::medianOfThree(T*& arr, int left, int right)
{
	int mid;
	mid = (left + right) / 2;

	//      left, mid, right의 숫자들의 크기를 순서대로 정렬할 것이다.
	if (arr[left] > arr[mid])//좌측과 중간값을 비교해서 정렬
	{
		swap(arr[left], arr[mid]);
	}
	if (arr[left] > arr[right])//기서 좌측을 우측값과 비교해서 정렬
	{
		swap(arr[left], arr[right]);
	}
	if (arr[mid] > arr[right])//마지막으로 중간값과 우측값을 비교해서 정렬
	{
		swap(arr[mid], arr[right]);
	}

	return mid;
}

//template three median 재귀
template <class T>
void QuickSort<T>::threeMedianRecursiveQuickSort(T*& arr, int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right + 1;
		T pivot;

		int medianMid = medianOfThree(arr, left, right);
		pivot = arr[medianMid];

		arr[medianMid] = arr[left];
		arr[left] = pivot;

		do
		{
			do
			{
				i++;
				if (i >= j)
				{
					break;
				}
			} while (arr[i] < pivot);
			do
			{
				j--;
				if (j <= 0)
				{
					break;
				}
			} while (arr[j] > pivot);
			if (i < j)
			{
				swap(arr[i], arr[j]);
			}
		} while (i < j);

		swap(arr[left], arr[j]);

		threeMedianRecursiveQuickSort(arr, left, j - 1);
		threeMedianRecursiveQuickSort(arr, j + 1, right);
	}

	return;
}