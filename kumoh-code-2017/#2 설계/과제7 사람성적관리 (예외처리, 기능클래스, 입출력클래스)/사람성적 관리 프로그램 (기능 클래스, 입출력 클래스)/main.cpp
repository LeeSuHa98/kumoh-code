/* 방학 스터디 과제 #1
학생 성적관리 프로그램
이름 : 손우규
학번 : 20120691
*/

#include "PersonList.h"
#include "ioHandler.h"
#include "TaskManager.h"

int main()
{
	PersonList p_list;
	ioHandler ioh;
	TaskManager tm;

	while (1)
	{
		// 메뉴
		int menu = ioh.getMenu();
		if (menu == EXIT) break; // 프로그램 종료

		switch (menu)
		{
		case INSERT:
			// 등록
			tm.registerPerson(p_list);
			break;
		case UNREGISTER:
			// 삭제
			tm.unregisterPerson(p_list);
			break;
		case DISPLAY:
			// 출력
			tm.displayPerson(p_list);
			break;
		case EXIT:
			// 종료
			return 0;
		}
	}
}