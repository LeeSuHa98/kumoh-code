#pragma once
#include "common.h"

//template 재귀
template <class T>
void quickSort(T* arr, const int left, const int right)
{
	if (left < right)
	{
		int i = left;
		int j = right + 1;
		T pivot = arr[left];

		do
		{
			do
			{
				i++;
			} while (i <= right && arr[i] < pivot);			// arr[i] >= pivot 일 때 종료
															// i > right일 경우 종료
			do
			{
				j--;
			} while (j >= left &&arr[j] > pivot);			// arr[j] <= pivot 일 때 종료
												// h가 계속 감소하더라도 arr[left]가 pivot이므로 언젠간 종료
			if (i < j)
				swap(arr[i], arr[j]);
		} while (i < j);


		swap(arr[left], arr[j]);

		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
	return;
}

//three median 탐색
template <class T>
int medianOfThree(T*& arr, int left, int right)
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
void threeMedianRecursiveQuickSort(T*& arr, int left, int right)
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

//template three median 반복
template <class T>
void threeMedianNonRecursiveQuickSort(T*& arr, int left, int right)
{
	stack<int> leftStack;
	stack<int> rightStack;
	leftStack.push(left);
	rightStack.push(right);

	while (leftStack.size() > 0 && rightStack.size() > 0)
	{
		left = leftStack.top();
		right = rightStack.top();
		int i = left;
		int j = right + 1;
		leftStack.pop();
		rightStack.pop();

		if (i < j - 1)
		{
			int mIndex = medianOfThree(arr, left, right);
			T pivot = arr[mIndex];
			arr[mIndex] = arr[left];
			arr[left] = pivot;
			do
			{
				do
				{
					i++;
				} while (pivot > arr[i]);
				do
				{
					j--;
				} while (pivot < arr[j]);

				if (i < j)
				{
					swap(arr[i], arr[j]);
				}
			} while (i < j);

			swap(arr[left], arr[j]);

			leftStack.push(j + 1);
			rightStack.push(right);
			leftStack.push(left);
			rightStack.push(j - 1);
		}
	}

	return;
}

template <class T>
void stdQuickSort(T*& arr, int size)
{
	std::sort(arr, arr + size);
	return;
}