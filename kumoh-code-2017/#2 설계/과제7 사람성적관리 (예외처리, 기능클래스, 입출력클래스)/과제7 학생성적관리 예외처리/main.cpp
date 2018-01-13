#include "Person.h"
#include "PersonList.h"

int main()
{
	PersonList p_list;

	while (1)
	{
		cout << "------ 성적관리 프로그램 ------" << endl;
		cout << "------ 1. 사람 성적 등록 ------" << endl;
		cout << "------ 2. 사람 성적 삭제 ------" << endl;
		cout << "------ 3. 사람 성적 출력 ------" << endl;
		cout << "------ 4. 프로그램 종료  ------" << endl;

		int select;
		cin >> select;

		switch (select)
		{
		case REGISTER:
			// 등록
			p_list.inputPerson();
			break;
		case UNREGISTER:
			// 삭제
			p_list.deletePerson();
			break;
		case DISPLAY:
			// 출력
			p_list.displayPerson();
			break;
		case EXIT:
			// 종료
			return 0;
		}
	}
}