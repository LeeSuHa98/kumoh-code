/*
�Է��� 10�� ���, 20�� ���, 30�� ���, 40�� ���, 50�� ��쿡 ���� �����غ��� �ݺ��Լ��� ����Լ��� �ӵ� ���̿� ���ؼ� ���Ͻÿ�.

ó�� 10, 20, 30�϶��� ���̸� ���� �� ������ 40���ʹ� �ӵ����̰� ������ ������. (����Լ��� �� ���� �ð��� �ɸ���)
�̴� ����Լ��� ������ ����ߴ� ���� �� ���̰� �ٽ� ����Ѵٴµ� �ִ�.

���� ���  getNthFiboNumRecursive(n)����
getNthFiboNumRecursive(4)�� �����ϸ� ����Լ� �ȿ��� getNthFiboNumRecursive(3)�� getNthFiboNumRecursive(2)�� ȣ���Ѵ�.
getNthFiboNumRecursive(3)���� �� getNthFiboNumRecursive(2)�� getNthFiboNumRecursive(1)�� �����ϰ� �ȴ�.
�����ϰ� ���ƿͼ� getNthFiboNumRecursive(4)�� ���� getNthFiboNumRecursive(3) "�ȿ���" ����ߴ� getNthFiboNumRecursive(2)�� �ٽ� �ѹ��� ����� �ؾ��Ѵ�.

�̴� n�� ������ ���� �� ���� �ߺ������ �ϱ� ������ ���� ��������.
*/

/*
50�� ���� �Ǻ���ġ ���� �������� ���� ����� ������ ������ ���ؼ� ���Ͻÿ�.

�Ǻ���ġ���� ���ҷ��� ��� ���ϴ� ���� �����÷ο찡 �߻��Ѵ�.
�׷��� ����� ������ �ٲ�� ��찡 �ִ�.
(0x7FFFFFFF + 1 = 0x80000000, integer���� �ֻ��� ��Ʈ�� ��ȣ��Ʈ�ν� 0�̸� ��� 1�̸� �����̴�.)
�� integer������ �ִ�
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
		cout << "���° �Ǻ���ġ ������ ���� ���Ͻʴϱ�? (�ݺ�)" << endl;
		cin >> select;
		cout << select << " ��° ������ �� : " << getNthFiboNumRepetitive(select) << endl;
		break;
	case 2:
		cout << "���° �Ǻ���ġ ������ ���� ���Ͻʴϱ�? (���)" << endl;
		cin >> select;
		cout << select << " ��° ������ �� : " << getNthFiboNumRecursive(select) << endl;
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
		if (i & 1) // Ȧ�� �Ǻ�
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