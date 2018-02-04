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
		cout << "(5입력 시 종료)" << endl;
		cout << "insert -> ";

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "갯수 입력 : ";
			cin >> num;
			leftTop(num);
			break;
		case 2:
			cout << "갯수 입력 : ";
			cin >> num;
			leftLow(num);
			break;
		case 3:
			cout << "갯수 입력 : ";
			cin >> num;
			rightTop(num);
			break;
		case 4:
			cout << "갯수 입력 : ";
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
	// 1. 좌변에 붙은 삼각형 찍기
	cout << "1. 좌변에 붙은 삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= num; i++)
	{
		//별을 찍는 루프
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		// 한 줄을 찍으면 개행
		cout << endl;
	}
}

void leftLow(int num)
{
	// 2. 우변에 붙은 삼각형
	cout << endl;
	cout << "2. 우변에 붙은 삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= num; i++)
	{
		int j;
		// 공백을 출력하는 루프
		for (j = 0; j <= 5 - i; j++)
		{
			cout << " ";
		}
		// 별을 출력하는 루프
		for (int k = 0; k + j <= 5; k++)
		{
			cout << "*";
		}
		// 공백과 별을 찍고 개행
		cout << endl;
	}
}

void rightTop(int num)
{
	// 3. 좌변에 붙은 역삼각형 찍기
	cout << endl;
	cout << "3. 좌변에 붙은 역삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= num; i++)
	{
		// 별을 몇 개 찍을 지를 결정하는 루프
		for (int j = 0; j <= 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void rightLow(int num)
{
	// 4. 우변에 붙은 역삼각형
	cout << endl;
	cout << "4. 우변에 붙은 역삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= num; i++)
	{
		// 공백을 출력하는 루프
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}
		// 별을 출력하는 루프
		for (int k = 0; k <= 5 - i; k++)
		{
			cout << "*";
		}
		// 공백과 별을 찍고 개행
		cout << endl;
	}
}