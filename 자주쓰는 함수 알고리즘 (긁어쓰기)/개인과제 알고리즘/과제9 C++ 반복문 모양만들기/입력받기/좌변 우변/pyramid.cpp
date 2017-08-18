#include <iostream>

using namespace std;

void leftTop(int num);
void rightTop(int num);
void leftLow(int num);
void rightLow(int num);

int main()
{
	int num;

	while (true)
	{
		cout << "(5�Է� �� ����)" << endl;
		cout << "insert -> ";

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "���� �Է� : ";
			cin >> num;
			leftTop(num);
			break;
		case 2:
			cout << "���� �Է� : ";
			cin >> num;
			leftLow(num);
			break;
		case 3:
			cout << "���� �Է� : ";
			cin >> num;
			rightTop(num);
			break;
		case 4:
			cout << "���� �Է� : ";
			cin >> num;
			rightLow(num);
			break;
		case 5:
			exit(1);
		}
	}
}

void leftTop(int num)
{
	// 1. �º��� ���� �ﰢ�� ���
	cout << "1. �º��� ���� �ﰢ��" << endl;
	// �� ���� ����� �������� �����ϴ� ����
	for (int i = 1; i <= num; i++)
	{
		//���� ��� ����
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		// �� ���� ������ ����
		cout << endl;
	}
}

void leftLow(int num)
{
	// 2. �캯�� ���� �ﰢ��
	cout << endl;
	cout << "2. �캯�� ���� �ﰢ��" << endl;
	// �� ���� ����� �������� �����ϴ� ����
	for (int i = 1; i <= num; i++)
	{
		int j;
		// ������ ����ϴ� ����
		for (j = 0; j <= 5 - i; j++)
		{
			cout << " ";
		}
		// ���� ����ϴ� ����
		for (int k = 0; k + j <= 5; k++)
		{
			cout << "*";
		}
		// ����� ���� ��� ����
		cout << endl;
	}
}

void rightTop(int num)
{
	// 3. �º��� ���� ���ﰢ�� ���
	cout << endl;
	cout << "3. �º��� ���� ���ﰢ��" << endl;
	// �� ���� ����� �������� �����ϴ� ����
	for (int i = 1; i <= num; i++)
	{
		// ���� �� �� ���� ���� �����ϴ� ����
		for (int j = 0; j <= 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void rightLow(int num)
{
	// 4. �캯�� ���� ���ﰢ��
	cout << endl;
	cout << "4. �캯�� ���� ���ﰢ��" << endl;
	// �� ���� ����� �������� �����ϴ� ����
	for (int i = 1; i <= num; i++)
	{
		// ������ ����ϴ� ����
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}
		// ���� ����ϴ� ����
		for (int k = 0; k <= 5 - i; k++)
		{
			cout << "*";
		}
		// ����� ���� ��� ����
		cout << endl;
	}
}