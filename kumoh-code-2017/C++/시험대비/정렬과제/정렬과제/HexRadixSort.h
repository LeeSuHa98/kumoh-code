#pragma once
#include "std.h"
#define HEX_NUMBER 16

class HexRadixSort
{
public:
	HexRadixSort() {}

	void Hex_RadixSort(unsigned int *a, unsigned int n)
	{
		unsigned int *b = new unsigned int[n];
		unsigned int i = 0;
		unsigned int m = 0;
		unsigned int exp = 1;

		clock_t begin, end;
		begin = clock();

		for (i = 0; i < n; i++)
		{
			if (a[i] > m)
				m = a[i];
		}

		while (m / exp > 0)
		{
			int arr[HEX_NUMBER] = { 0 };

			for (i = 0; i < n; i++)
			{
				arr[a[i] / exp % HEX_NUMBER]++;
			}

			for (i = 1; i < HEX_NUMBER; i++)
			{
				arr[i] += arr[i - 1];
			}

			for (i = n - 1; i >= 0; i--)
			{
				b[--arr[a[i] / exp % HEX_NUMBER]] = a[i];
				if (i == 0) break;
			}

			for (i = 0; i < n; i++)
			{
				a[i] = b[i];
			}

			exp = exp * HEX_NUMBER;
		}

		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "Radix Sort(16Áø¼ö,modulo)(" << n << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;
		
	}
};
