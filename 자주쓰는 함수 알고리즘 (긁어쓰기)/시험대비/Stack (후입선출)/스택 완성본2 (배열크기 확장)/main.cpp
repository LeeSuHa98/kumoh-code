#include "Stack.h"

int main()
{
	Stack<string> s;

	while (1)
	{
		cout << "Stack 후입선출 (Last In First Out)" << endl;
		cout << "------------ 1. Push   ------------" << endl;
		cout << "------------ 2. Pop    ------------" << endl;
		cout << "------------ 3. Show   ------------" << endl;
		cout << "------------ 4. Resize ------------" << endl;
		cout << "------------ 5. Exit   ------------" << endl;
		cout << " 선택 : ";
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
			// Resize
			s.resize();
			break;
		case 5:
			// Exit
			return 0;
		}
	}
}