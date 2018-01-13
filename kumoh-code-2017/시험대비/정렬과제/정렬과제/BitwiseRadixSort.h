#pragma once

#define HEX_NUMBER 16 

class BitwiseRadixSort
{
public:
	BitwiseRadixSort() {}

	int log16(int exp)
	{
		int count = 0;

		while (exp / HEX_NUMBER != 0)
		{
			count++;
			exp = exp / HEX_NUMBER;
		}

		return count;
	}

	void Bitwise_RadixSort(unsigned int *a, unsigned int n)
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
			int arr[HEX_NUMBER] = { 0 };

			for (i = 0; i < n; i++)
			{
				unsigned int tmp = a[i];

				for (int k = 0; k < log16(exp); k++)
				{
					tmp = tmp >> 4; //16진수 이므로 비트를 네칸 이동
				}
				tmp = tmp & (HEX_NUMBER - 1);	// Bitwise

				arr[tmp]++;
			}

			for (i = 1; i < HEX_NUMBER; i++)
			{
				arr[i] += arr[i - 1];
			}

			for (i = n - 1; i >= 0; i--)
			{
				unsigned int tmp = a[i];

				for (int k = 0; k < log16(exp); k++)
				{
					tmp = tmp >> 4; //16진수 이므로 비트를 네칸 이동
				}

				tmp = tmp & (HEX_NUMBER - 1);	// Bitwise

				b[--arr[tmp]] = a[i];

				if (i == 0) break;
			}

			for (i = 0; i < n; i++)
			{
				a[i] = b[i];
			}

			exp *= HEX_NUMBER;
		}

		end = clock();
		clock_t resultTime = ((double)(end - begin));
		cout << "Radix Sort(16진수,masking,shift)(" << n << ") : " << (double)resultTime / CLOCKS_PER_SEC << endl;
	}
};
