#include <iostream>

using namespace std;

int main()
{
	// 1. 좌변에 붙은 삼각형 찍기
	cout << "1. 좌변에 붙은 삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= 5; i++)
	{
		//별을 찍는 루프
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		// 한 줄을 찍으면 개행
		cout << endl;
	}

	// 2. 역삼각형 찍기
	cout << endl;
	cout << "2. 역삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= 5; i++)
	{
		// 별을 몇 개 찍을 지를 결정하는 루프
		for (int j = 0; j <= 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 3. 우변에 붙은 삼각형
	cout << endl;
	cout << "3. 우변에 붙은 삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= 5; i++)
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

	// 4. 우변에 붙은 역삼각형
	cout << endl;
	cout << "4. 우변에 붙은 역삼각형" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= 5; i++)
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

	// 5. 피라미드
	cout << endl;
	cout << "5. 피라미드" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i<= 5; i++)
	{
		// 공백을 출력하는 루프
		for (int j = 1; j <= (5*2) / 2 - i; j++)
		{
			cout << " ";
		}
		// 별을 출력하는 루프
		for (int k = 0; k < (i * 2) - 1; k++)
		{
			cout << "*";
		}
		// 공백과 별을 찍고 개행
		cout << endl;
	}

	// 6. 역피라미드
	cout << endl;
	cout << "6. 역피라미드" << endl;
	// 몇 줄을 출력할 것인지를 결정하는 루프
	for (int i = 1; i <= 5; i++)
	{
		// 공백을 출력하는 루프
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}
		// 별을 출력하는 루프
		for (int k = 0; k < (5 * 2) - ((i - 1) * 2) - 1; k++)
		{
			cout << "*";
		}
		// 공백과 별을 찍고 개행
		cout << endl;
	}

	// 7. 다이아몬드
	cout << endl;
	cout << "7. 다이아몬드" << endl;
	// 1. 다이아몬드 상단
	// 다이아몬드는 다섯 줄이 주어졌을 때 아홉 줄을 출력하도록.
	for (int i = 1; i <= 5; i++)
	{
		// 공백을 출력하는 루프
		for (int j = 1; j <= (5 * 2) / 2 - i; j++)
		{
			cout << " ";
		}
		for (int k = 1; k <= (i * 2) - 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	// 2. 다이아몬드 하단
	// 하단 줄 수는 상단보다 1 적다.
	for (int i = 1; i <= 5 - 1; i++)
	{
		// 공백을 출력하는 루프
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		// 별을 출력하는 루프
		for (int k = 0; k < 5 * 2 - (2 * i) - 1; k++)
		{
			cout << "*";
		}
		// 공백과 별을 찍고 개행
		cout << endl;
	}

	// 8. 좌측에 붙은 모래시계 반쪽
	cout << endl;
	cout << "8. 좌측에 붙은 모래시계 반쪽" << endl;
	// 1. 모래시계 상단
	for (int i = 1; i <= 5; i++)
	{
		// 별을 출력하는 루프
		for (int j = 0; j < 5 - i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	// 2. 모래시계 하단
	for (int i = 1; i <= 5 - 1; i++)
	{
		// 별을 찍는 루프
		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}
		// 공백과 별을 찍고 개행
		cout << endl;
	}
}