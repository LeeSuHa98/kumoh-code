#include "Word.h"
#include "WordList.h"

int main()
{
	WordList w_list;

	while (1)
	{
		cout << "------ 영어 단어 맞추기 ------" << endl;
		cout << "------ 1. 어휘 삽입     ------" << endl;
		cout << "------ 2. 어휘 테스트   ------" << endl;
		cout << "------ 3. 프로그램 종료 ------" << endl;
		cout << "선택 : ";

		int select;
		cin >> select;

		switch (select)
		{
		case 1:
			// 어휘 삽입
			w_list.insertWord();
			break;
		case 2:
			// 어휘 테스트
			w_list.testWord();
			break;
		case 3:
			// 프로그램 종료
			return 0;
		}
	}
}