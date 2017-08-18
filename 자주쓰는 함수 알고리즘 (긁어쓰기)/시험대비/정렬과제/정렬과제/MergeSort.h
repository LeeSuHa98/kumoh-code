#pragma once
#include "std.h"
template <class T>

class MergeSort
{
public:
	MergeSort(void) {}

	T* getSort_Merge_NonR(T *arr, const int count)
	{
		T *a = new T[count + 1];

		for (int i = 1; i < count + 1; i++)
		{
			a[i] = arr[i - 1];
		}

		return nonRecursiveSort(a, count);
	}
	T* getSort_Merge_R(T *arr, const int count)
	{
		T *a = new T[count + 1];

		for (int i = 1; i < count + 1; i++)
		{
			a[i] = arr[i - 1];
		}

		return recursiveMergeSort(a, count);
	}
	T* getSort_Merge_Natural(T *arr, const int count)
	{
		T *a = new T[count + 1];

		for (int i = 1; i < count + 1; i++)
		{
			a[i] = arr[i - 1];
		}

		return naturalSort(a, count);
	}

	int natural(T *arr, T *temp, const int i, const int m, const int n)
	{
		int i1;
		int iResult;
		int i2;

		for (i1 = i, iResult = i, i2 = m + 1; i1 <= m&&i2 <= n; iResult++)
		{
			if (arr[i1] <= arr[i2])
			{
				temp[iResult] = arr[i1];
				i1++;
			}
			else
			{
				temp[iResult] = arr[i2];
				i2++;
			}
		}

		copy(arr + i1, arr + m + 1, temp + iResult);
		copy(arr + i2, arr + n + 1, temp + iResult);

		return n - i + 1;
	}

	void naturalPass(T *arr, T *resultList, queue<int> &Queue, const int n)
	{
		int f_size;
		int s_size;
		int i;

		for (i = 1; i + Queue.front() - 1<n; )
		{
			f_size = Queue.front(); Queue.pop();
			s_size = Queue.front(); Queue.pop();

			Queue.push(natural(arr, resultList, i, i + f_size - 1, i + f_size + s_size - 1));

			i = i + f_size + s_size;
		}


		if (i + Queue.front() - 1 == n)
		{
			copy(arr + i, arr + n + 1, resultList + i);
			Queue.push(Queue.front());
			Queue.pop();
		}

	}

	T* naturalSort(T *a, const int ne)
	{
		int n = ne - 1;

		begin = clock();
		T *t_arr = new T[n + 1];
		queue<int> Queue;

		for (int i = 1, j = 1; i <= n; i++)
		{
			if (a[i]>a[i + 1] || i == n)
			{
				Queue.push(j);
				j = 1;
			}
			else if (a[i] <= a[i + 1])
			{
				j++;
			}
		}

		for (int i = Queue.front(); i < n; i = Queue.front())
		{
			naturalPass(a, t_arr, Queue, n);

			naturalPass(t_arr, a, Queue, n);

		}

		delete[] t_arr;
		end = clock();
		cout << "Natural Merge Sort(" << n + 1 << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

		T* temp = new T[n];

		for (int i = 0; i < n; i++)
		{
			temp[i] = a[i + 1];
		}

		return temp;
	}

	void recursiveList2(T *a, int *link, const int n, int first)
	{
		for (int i = 1; i<n; i++)
		{
			while (first<i)
			{
				first = link[first];
			}

			int q = link[first];
			if (first != i)
			{
				swap(a[i], a[first]);
				link[first] = link[i];
				link[i] = first;
			}
			first = q;
		}
	}
	int recursiveList(T *a, int *link, const int start1, const int start2)
	{
		int i1;
		int i2;
		int iResult = 0;
		for (i1 = start1, i2 = start2; i1&&i2; )
		{
			if (a[i1] <= a[i2])
			{
				link[iResult] = i1;
				iResult = i1;
				i1 = link[i1];
			}
			else
			{
				link[iResult] = i2;
				iResult = i2;
				i2 = link[i2];
			}
		}

		if (i1 == 0)
		{
			link[iResult] = i2;
		}
		else
		{
			link[iResult] = i1;
		}
		return link[0];
	}

	int recursive(T *a, int *link, const int left, const int right)
	{
		if (left >= right)
		{
			return left;
		}
		int mid = (left + right) / 2;
		return recursiveList(a, link, recursive(a, link, left, mid), recursive(a, link, mid + 1, right));
	}

	T* recursiveMergeSort(T *arr, const int n)
	{
		begin = clock();

		int *link = new int[n + 1];

		for (int i = 1; i < n + 1; i++)
		{
			link[i] = 0;
		}

		recursiveList2(arr, link, n, recursive(arr, link, 1, n));

		end = clock();

		delete[] link;

		cout << "R-Merge Sort(" << n << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

		T* temp = new T[n];

		for (int i = 0; i < n; i++)
		{
			temp[i] = arr[i + 1];
		}

		return temp;
	}


	void nonRecursive(T *arr, T *temp, const int l, const int m, const int n)
	{
		int i1;
		int iResult;
		int i2;

		for (i1 = l, iResult = l, i2 = m + 1; i1 <= m&&i2 <= n; iResult++)
		{
			if (arr[i1] <= arr[i2])
			{
				temp[iResult] = arr[i1];
				i1++;
			}
			else
			{
				temp[iResult] = arr[i2];
				i2++;
			}
		}
		copy(arr + i1, arr + m + 1, temp + iResult);
		copy(arr + i2, arr + n + 1, temp + iResult);
	}
	void nonRecursivePass(T *arr, T *resultList, const int n, const int s)
	{
		int i;
		for (i = 1; i<n - 2 * s + 1; i = i + 2 * s)
		{
			nonRecursive(arr, resultList, i, i + s - 1, i + 2 * s - 1);
		}
		if ((i + s - 1)<n)
		{
			nonRecursive(arr, resultList, i, i + s - 1, n);
		}
		else
		{
			copy(arr + i, arr + n + 1, resultList + i);
		}
	}
	T* nonRecursiveSort(T *a, const int n)
	{
		begin = clock();
		T *temp = new T[n + 1];

		for (int l = 1; l<n; l = l * 2)
		{
			nonRecursivePass(a, temp, n, l);

			l = l * 2;

			nonRecursivePass(temp, a, n, l);
		}

		delete[] temp;
		end = clock();
		cout << "NonR-Merge Sort(" << n << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

		T* t = new T[n];

		for (int i = 0; i < n; i++)
		{
			t[i] = a[i + 1];
		}
		


		return t;
	}

private:
	clock_t begin;
	clock_t end;

};
