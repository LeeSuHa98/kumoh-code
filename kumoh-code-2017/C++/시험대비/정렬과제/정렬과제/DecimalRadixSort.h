#pragma once
#define DECIMAL_NUMBER 10 

class DecimalRadixSort
{
public:
	DecimalRadixSort() {}

	void RadixSort(unsigned int *a, unsigned int n)
	{
		clock_t begin, end;

		begin = clock();

		unsigned int *b = new unsigned int[n];
		unsigned int i = 0;
		unsigned int m = 0;
		unsigned int exp = 1;

		for (i = 0; i < n; i++)
		{
			if (a[i] > m)
				m = a[i];
		}

		while (m / exp > 0)
		{
			int arr[DECIMAL_NUMBER] = { 0 };

			for (i = 0; i < n; i++)
				arr[a[i] / exp % DECIMAL_NUMBER]++;

			for (i = 1; i < DECIMAL_NUMBER; i++)
				arr[i] += arr[i - 1];

			for (i = n - 1; i >= 0; i--)
			{
				b[--arr[a[i] / exp % DECIMAL_NUMBER]] = a[i];
				if (i == 0) break;
			}
			for (i = 0; i < n; i++)
				a[i] = b[i];

			exp = exp * DECIMAL_NUMBER;
		}

		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "Radix Sort(10Áø¼ö,modulo)(" << n << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;
	}
};

