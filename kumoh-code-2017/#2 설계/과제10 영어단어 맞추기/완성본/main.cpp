#include "Word.h"
#include "WordList.h"

int main()
{
	WordList w_list;

	while (1)
	{
		cout << "------ ���� �ܾ� ���߱� ------" << endl;
		cout << "------ 1. ���� ����     ------" << endl;
		cout << "------ 2. ���� �׽�Ʈ   ------" << endl;
		cout << "------ 3. ���α׷� ���� ------" << endl;
		cout << "���� : ";

		int select;
		cin >> select;

		switch (select)
		{
		case 1:
			// ���� ����
			w_list.insertWord();
			break;
		case 2:
			// ���� �׽�Ʈ
			w_list.testWord();
			break;
		case 3:
			// ���α׷� ����
			return 0;
		}
	}
}