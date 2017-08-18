#include "Stack.h"

int main()
{
	Stack<string> s;

	while (1)
	{
		cout << "Stack ���Լ��� (Last In First Out)" << endl;
		cout << "------------ 1. Push  ------------" << endl;
		cout << "------------ 2. Pop   ------------" << endl;
		cout << "------------ 3. Show  ------------" << endl;
		cout << "------------ 4. Exit  ------------" << endl;
		cout << " ���� : ";
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
			// Push
			s.pushShow();
			break;
		case 2:
			// Pop
			s.popShow();
			break;
		case 3:
			// Show
			s.stackShow();
			break;
		case 4:
			// Exit
			return 0;
		}
	}
}