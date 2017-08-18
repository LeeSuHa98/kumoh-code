#include "Queue.h"

int main()
{
	Queue<string> q;

	while (1)
	{
		cout << "Queue 선입선출 (First In First Out)" << endl;
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
			q.pushShow();
			break;
		case 2:
			// Pop
			q.popShow();
			break;
		case 3:
			// Show
			q.QueueShow();
			break;
		case 4:
			// Resize
			q.resize();
			break;
		case 5:
			// Exit
			return 0;
		}
	}
}