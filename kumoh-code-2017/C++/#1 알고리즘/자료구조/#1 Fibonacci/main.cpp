/*
입력이 10이 경우, 20인 경우, 30인 경우, 40인 경우, 50인 경우에 대해 수행해보고 반복함수와 재귀함수의 속도 차이에 대해서 논하시오.

처음 10, 20, 30일때는 차이를 느낄 수 없지만 40부터는 속도차이가 눈으로 보였다. (재귀함수가 더 많은 시간이 걸린다)
이는 재귀함수가 이전에 계산했던 값을 몇 번이고 다시 계산한다는데 있다.

예를 들어  getNthFiboNumRecursive(n)에서
getNthFiboNumRecursive(4)를 실행하면 재귀함수 안에서 getNthFiboNumRecursive(3)과 getNthFiboNumRecursive(2)를 호출한다.
getNthFiboNumRecursive(3)으로 들어가 getNthFiboNumRecursive(2)와 getNthFiboNumRecursive(1)을 수행하게 된다.
수행하고 돌아와서 getNthFiboNumRecursive(4)를 보면 getNthFiboNumRecursive(3) "안에서" 계산했던 getNthFiboNumRecursive(2)를 다시 한번더 계산을 해야한다.

이는 n이 증가할 수록 더 많이 중복계산을 하기 때문에 점점 느려진다.
*/

/*
50에 대한 피보나치 값이 예상하지 못한 결과가 나오는 이유에 대해서 논하시오.

피보나치수를 구할려고 계속 더하다 보면 오버플로우가 발생한다.
그러면 양수가 음수로 바뀌는 경우가 있다.
(0x7FFFFFFF + 1 = 0x80000000, integer에서 최상위 비트는 부호비트로써 0이면 양수 1이면 음수이다.)
ㄴ integer변수의 최댓값
*/

#include <iostream>

using namespace std;

int getNthFiboNumRepetitive(int n);
int getNthFiboNumRecursive(int n);

int main()
{
	cout << "------ Fibonacci Program ------" << endl;
	cout << "------ 1. Repetitive     ------" << endl;
	cout << "------ 2. Reculsive      ------" << endl;
	cout << "------ 3. Exit           ------" << endl;

	int select;

	cin >> select;

	switch (select)
	{
	case 1:
		cout << "몇번째 피보나치 수열의 값을 원하십니까? (반복)" << endl;
		cin >> select;
		cout << select << " 번째 수열의 값 : " << getNthFiboNumRepetitive(select) << endl;
		break;
	case 2:
		cout << "몇번째 피보나치 수열의 값을 원하십니까? (재귀)" << endl;
		cin >> select;
		cout << select << " 번째 수열의 값 : " << getNthFiboNumRecursive(select) << endl;
		break;
	case 3:
		exit(1);
	}

	return 0;
}

int getNthFiboNumRepetitive(int n)
{
	if (n < 0)
		return 0;

	if (n <= 1)
		return n;

	int val1, val2;
	int fibo;

	val1 = 0; val2 = 1;
	for (int i = 2; i <= n; ++i)
	{
		fibo = val1 + val2;
		if (i & 1) // 홀수 판별
			val2 = fibo;
		else
			val1 = fibo;
	}

	return fibo;
}

int getNthFiboNumRecursive(int n)
{
	if (n < 0)
		return 0;

	if (n <= 1)
		return n;
	else
		return getNthFiboNumRecursive(n - 1) + getNthFiboNumRecursive(n - 2);
}