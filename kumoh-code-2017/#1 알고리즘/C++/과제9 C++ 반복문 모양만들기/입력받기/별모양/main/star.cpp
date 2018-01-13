#include <iostream>
using namespace std;

void makeHead(int num);
int makeBody(int num);
void makeTail(int bodyStar, int num);

void main()
{
	int bodyStar = 0;
	int num;

	cout << "별의 크기(높이)를 입력하세요 (높이=입력값x3) : ";
	cin >> num;

	makeHead(num);
	bodyStar = makeBody(num);
	makeTail(bodyStar, num);
}

void makeHead(int num)
{	
	int star = 1;
	int blank = num * 2;

	for (int i = 0; i < num; i++)
	{
		for (int i = blank; i >= 1; i--)
		{
			cout << " ";
		}

		for (int j = 1; j <= star; j++)
		{
			cout << "*";
		}

		cout << endl;
		star = star + 2;
		blank = blank - 1;
	}
}

int makeBody(int num)
{
	int star = num * 4.5;
	int blank = 0;

	for (int i = 0; i < num; i++)
	{
		if (blank != 0)
		{
			for (int i = 0; i < blank; i++)
			{
				cout << " ";
			}
		}

		for (int i = 0; i < star; i++)
		{
			cout << "*";
		}

		cout << endl;
		star = star - 2;
		blank = blank + 1;
	}

	return star;
}

void makeTail(int bodyStar, int num)
{
	int body_Star = bodyStar + 2;
	int firstBlank = num - 1;
	int star = num;
	int middleBlank = body_Star - (star * 2);

	for (int i = 0; i < num; i++)
	{
		if(firstBlank != 0)
		{
			for (int j = firstBlank; j > 0; j--)
			{
				cout << " ";
			}
		}

		for (int j = star; j > 0; j--)
		{
			cout << "*";
		}

		for (int j = middleBlank; j > 0; j--)
		{
			cout << " ";
		}

		for (int j = star; j > 0; j--)
		{
			cout << "*";
		}

		cout << endl;
		firstBlank = firstBlank - 1;
		star = star - 1;
		middleBlank = middleBlank + 4;
	}
}