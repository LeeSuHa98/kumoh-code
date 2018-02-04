#pragma once
#include "common.h"

class RadixSort
{
public:
	RadixSort() {}
	~RadixSort() {}

	void getHex(string* hexArr, int* arr); // 10진수를 16진수로 변환
	void getDec(string* hexArr, int * arr); // 16진수를 10진수로 변환
	int getLength(int number);
	int convertInteager(char data);
	string convertHexChar(int data);
	string reverseString(string str);
	void hexademicalRadixSort(string* hexArr, int size, int p, int k);
	void maskingAndShiftRadixSort(int* arr, int size, int p, int k);
	void demicalRadixSort(int* arr, int size, int p, int k);
};

// 16진수 구하기 modulo 연산
// 나눗셈의 나머지를 계산하는 수학적 연산. 예를 들면 37 modulo 6=1.
void RadixSort::getHex(string* hexArr, int* arr)
{
	int count = 0;

	while (count < 50000)
	{
		string temp = "";
		if (arr[count] > 15)
		{
			while (arr[count] > 15)
			{
				temp += convertHexChar(arr[count] % 16);
				arr[count] = arr[count] / 16;
				if (arr[count] <= 15)
				{
					temp += convertHexChar(arr[count]);
					hexArr[count] = reverseString(temp);
					break;
				}
			}
			count++;
		}
		else
		{
			hexArr[count] = convertHexChar(arr[count]);
			count++;
		}
	}
}

void RadixSort::getDec(string * hexArr, int * arr)
{
	int count = 0;

	while (count < 50000)
	{
		string target = hexArr[count];
		int x = 1;

		for (int i = target.length() - 1; i >= 0; i--)
		{
			arr[count] += convertInteager(target[i]) * x;
			x *= 16;
		}

		count++;
	}
}


// 숫자 자리수 구하기
int RadixSort::getLength(int index)
{
	int length = 0;

	do
	{
		index = int(index / 10);
		length++;
	} while (index > 0);

	return length;
}

//문자 -> 해당하는 16진수 정수 반환
int RadixSort::convertInteager(char data)
{
	if (data == '0')
		return 0;
	else if (data == '1')
	{
		return 1;
	}
	else if (data == '2')
	{
		return 2;
	}
	else if (data == '3')
		return 3;
	else if (data == '4')
		return 4;
	else if (data == '5')
		return 5;
	else if (data == '6')
		return 6;
	else if (data == '7')
		return 7;
	else if (data == '8')
		return 8;
	else if (data == '9')
		return 9;
	else if (data == 'A')
	{
		return 10;
	}
	else if (data == 'B')
	{
		return 11;
	}
	else if (data == 'C')
	{
		return 12;
	}
	else if (data == 'D')
	{
		return 13;
	}
	else if (data == 'E')
	{
		return 14;
	}
	else if (data == 'F')
	{
		return 15;
	}
}

// 16진수 형 변환
string RadixSort::convertHexChar(int data)
{
	switch (data)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return to_string(data);
	case 10:
		return "A";
	case 11:
		return "B";
	case 12:
		return "C";
	case 13:
		return "D";
	case 14:
		return "E";
	case 15:
		return "F";
	default:
		return NULL;
		break;
	}
	return NULL;
}

// 문자열 반전
string RadixSort::reverseString(string str)
{
	string reverse;

	for (int i = 0; i < str.size(); i++)
	{
		reverse += str.substr(str.size() - i - 1, 1);
	}

	return reverse;
}

//size data의 갯수 30
//p 숫자의 최대 자리 수 , 5
//k 기수 16
//1) modulo 연산(%) 으로 16진수 LSB 값을 얻어 정렬하는 radix sort
void RadixSort::hexademicalRadixSort(string* hexArr, int size, int p, int k)
{
	//버킷생성
	queue<string>* q = new queue<string>[k];

	int count = 0;

	for (int j = 0; j < p; j++)
	{

		for (int i = 0; i < size; i++)
		{

			if (count >= hexArr[i].size())
			{
				q[0].push(hexArr[i]);
				continue;
			}

			int index = hexArr[i].size() - 1 - count;

			q[convertInteager(hexArr[i][index])].push(hexArr[i]);
		}

		int tmpCnt = 0;
		for (int i = 0; i < k; i++)
		{

			while (!q[i].empty())
			{
				hexArr[tmpCnt] = q[i].front();
				q[i].pop();
				tmpCnt++;
			}
		}
		count++;
	}
}

//2) masking(&)과 shift 연산(>>)연산으로 16진수 LSB값을 얻어 정렬하는 radix sort
void RadixSort::maskingAndShiftRadixSort(int* arr, int size, int p, int k)
{
	queue<int>* q = new queue<int>[k];

	int count = 0;
	int mask = 15;
	int temp = 0;
	//최대 자리수 만큼 반복
	for (int j = 0; j < p; j++)
	{

		//size 만큼 반복
		for (int i = 0; i < size; i++)
		{

			if (count >= getLength(arr[i]))
			{
				q[0].push(arr[i]);
				continue;
			}

			int tmpCnt = 0;
			temp = arr[i];
			while (count > tmpCnt)
			{
				temp >>= 4;
				tmpCnt++;
			}

			temp &= mask;

			q[temp].push(arr[i]);
		}

		int tmpCnt = 0;
		for (int i = 0; i < k; i++)
		{

			while (!q[i].empty())
			{
				arr[tmpCnt] = q[i].front();
				q[i].pop();
				tmpCnt++;
			}
		}
		count++;
	}
}

//3) modulo 연산(%) 으로 10진수 LSB 값을 얻어 정렬하는 radix sort
void RadixSort::demicalRadixSort(int* arr, int size, int p, int k)
{
	queue<int>* q = new queue<int>[k];

	int count = 0;
	int temp = 0;
	//최대 자리수 만큼 반복
	for (int j = 0; j < p; j++)
	{
		//size 만큼 반복
		for (int i = 0; i < size; i++)
		{
			if (count >= getLength(arr[i]))
			{
				q[0].push(arr[i]);
				continue;
			}
			int tmpCnt = 0;
			temp = arr[i];
			while (count > tmpCnt)
			{
				temp /= 10;
				tmpCnt++;
			}
			temp %= 10;
			q[temp].push(arr[i]);
		}
		int tmpCnt = 0;
		for (int i = 0; i < k; i++)
		{
			while (!q[i].empty())
			{
				arr[tmpCnt] = q[i].front();
				q[i].pop();
				tmpCnt++;
			}
		}
		count++;
	}
}