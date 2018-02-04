#pragma once

#include "std.h"

template <class T>
class QuickSort
{
public:
	void getSort_quick(T* arr, const int count)
	{
		clock_t begin, end;

		begin = clock();

		quickSort(arr, 0, count-1 );

		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "Quick Sort(" << count << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;
	}

	void getSort_quick_mid(T* arr, const int count)
	{
		clock_t begin, end;

		begin = clock();

		quickSort2(arr, 0, count - 1);

		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "Mid-Quick Sort(" << count << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;
	}

	void getSort_quick_iter(T* arr, const int count)
	{
		clock_t begin, end;

		begin = clock();

		iteratingQuickSort(arr, 0, count - 1);

		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "NonR-Mid-Quick Sort(" << count << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;
	}

	int getMiddleIndex(T* a, const int left, const int right)
	{
		if (right - left <= 1)
			return left;

		if (a[left]<a[right])
		{
			if (a[right]<a[(left + right) / 2])
			{
				return right;
			}
			if (a[right] == a[(left + right) / 2] || a[left] == a[(left + right) / 2])
			{
				return (left + right) / 2;
			}
			if (a[right]>a[(left + right) / 2])
			{
				if (a[(left + right) / 2]<a[left])
					return left;
				if (a[(left + right) / 2]>a[left])
					return (left + right) / 2;
			}
		}
		if (a[left] == a[right])
		{
			return left;
		}
		if (a[left]>a[right])
		{
			if (a[left]<a[(left + right) / 2])
			{
				return left;
			}
			if (a[right] == a[(left + right) / 2] || a[left] == a[(left + right) / 2])
			{
				return (left + right) / 2;
			}
			if (a[left]>a[(left + right) / 2])
			{
				if (a[right]<a[(left + right) / 2])
					return (left + right) / 2;

				if (a[right]>a[(left + right) / 2])
					return right;
			}
		}
	}

	void quickSort2(T* a, const int left, const int right)
	{
		if (left<right) {
			int pivotNum = getMiddleIndex(a, left, right);
			swap(a[pivotNum], a[left]);
			int i = left, j = right + 1;
			T pivot = a[left];
			do {
				do i++; while (i <= right && a[i]<pivot);
				do j--; while (j >= left && a[j]>pivot);
				if (i<j) swap(a[i], a[j]);
			} while (i<j);
			swap(a[left], a[j]);

			quickSort(a, left, j - 1);
			quickSort(a, j + 1, right);
		}

	}

	void quickSort(T* a, const int left, const int right)
	{
		if (left<right) {
			int i = left, j = right + 1;
			T pivot = a[left];
			do {
				do i++; while (i <= right && a[i]<pivot);
				do j--; while (j >= left && a[j]>pivot);
				if (i<j) swap(a[i], a[j]);
			} while (i<j);
			swap(a[left], a[j]);

			quickSort(a, left, j - 1);
			quickSort(a, j + 1, right);
		}
	}


	void iteratingQuickSort(T* a, int left, int right)
	{
		stack<int> leftStack, rightStack;
		int arrSize = right;

		leftStack.push(left);
		rightStack.push(right);

		do
		{
			left = leftStack.top();
			leftStack.pop();
			right = rightStack.top();
			rightStack.pop();

			int pivotNum = getMiddleIndex(a, left, right);
			swap(a[left], a[pivotNum]);
			int i = left;
			int j = right + 1;
			T pivot = a[left];

			do {
				do i++; while (i <= right && a[i]<pivot);
				do j--; while (j >= left && a[j]>pivot);

				if (i<j) swap(a[i], a[j]);
				else swap(a[left], a[j]);
			} while (i<j);

			if (right>left && j + 1<right)
			{
				leftStack.push(j + 1);
				rightStack.push(right);
			}
			if (right>left && j - 1>left)
			{
				leftStack.push(left);
				rightStack.push(j - 1);
			}
			if (rightStack.size() == 0)
				break;
		} while (true);
	}

};
