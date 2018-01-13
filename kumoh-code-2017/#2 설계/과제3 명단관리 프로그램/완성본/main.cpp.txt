#include "Member.h"
#include "MemberList.h"
#include "ioHandler.h"
#include "TaskManager.h"

int main()
{
	MemberList m_list;
	ioHandler ioh;
	TaskManager tm;

	while (true)
	{
		int menu = ioh.getMenu();
		if (menu == EXIT) break; // 프로그램 종료

		switch (menu)
		{
		case 1:
			// 명단 정보 등록
			tm.registerMember(m_list);
			break;
		case 2:
			// 명단 정보 삭제
			tm.unregisterMember(m_list);
			break;
		case 3:
			// 명단 정보 수정
			tm.changeMember(m_list);
			break;
		case 4:
			// 명단 정보 출력
			tm.displayMember(m_list);
			break;
		default:
			// 예외 처리
			cout << " 잘못 입력하셨습니다 " << endl;
			exit(1);
		}
	}
}