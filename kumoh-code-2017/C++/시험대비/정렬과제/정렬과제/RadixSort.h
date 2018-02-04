#pragma once

#include "std.h"

template <class T>
class RadixSort
{
public:
	RadixSort() {}

	void getSort(T* arr, const int count)
	{
		radixSort(arr, count);
	}

	void radixSort(T* arr, const int count)
	{
		int i;

		// find the max number in the given list.
		// to be used in loop termination part.
		T maxNumber = arr[0];
		for (i = 1; i < count; i++)
		{
			if (arr[i] > maxNumber)
				maxNumber = arr[i];
		}

		// run the loop for each of the decimal places
		T exp = 1;
		T* tmpBuffer = new T[count];
		while (maxNumber / exp > 0)
		{
			T decimalBucket[10] = { 0 };
			// count the occurences in this decimal digit.
			for (i = 0; i < count; i++)
				decimalBucket[arr[i] / exp % 10]++;

			// Prepare the position counters to be used for re-ordering the numbers
			// for this decimal place.
			for (i = 1; i < count; i++)
				decimalBucket[i] += decimalBucket[i - 1];

			// Re order the numbers in the tmpbuffer and later copy back to original buffer.
			for (i = count - 1; i >= 0; i--)
				tmpBuffer[--decimalBucket[arr[i] / exp % 10]] = arr[i];
			for (i = 0; i < count; i++)
				arr[i] = tmpBuffer[i];

			// Move to next decimal place.
			exp *= 10;
		}


		for (int i = 0; i < count; i++)
			cout << arr[i] << endl;

	}
};