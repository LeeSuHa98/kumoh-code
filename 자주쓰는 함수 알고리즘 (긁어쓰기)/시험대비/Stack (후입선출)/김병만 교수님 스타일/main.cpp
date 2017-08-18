#include "Stack.h"

int main()
{
	Stack<int> q1;
	Stack<float> q2;

	int I;

	q1.init();
	q2.init();

	q1.Push(4);
	q2.Push(5.5);

	I = q1.get() + q2.get();
	cout << I << endl;

	q1.Push(5);
	q2.Push(6.5);

	q1.Show();
	q2.Show();

	return 0;
}