#include "Stack.h"

int main()
{
	Stack s;
	int data;
	//cout << " µ¥ÀÌÅÍ : " << endl;
	//cin >> data;

	//s.push(data);

	//cout << data << endl;

	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return 0;
}