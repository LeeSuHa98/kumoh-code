#include <iostream>
#include "Student.h"
#include "StudentList.h"
#include "TaskManager.h"
#include "ioHandler.h"

using namespace std;

int main()
{
	StudentList s_list;
	TaskManager tm;
	ioHandler ioh;

	while (true)
	{
		// 메뉴
		int menu = ioh.getMenu();
		if (menu == EXIT) break;

		switch (menu)
		{
		case REGISTER :
			// 학생 등록
			tm.registerStudent(s_list);
			break;
		case UNREGISTER :
			// 학생 삭제
			tm.unregisterStudent(s_list);
			break;
		case CHANGE :
			// 학생 수정
			tm.changeStudent(s_list);
			break;
		case DISPLAY :
			// 학생 출력
			tm.displayStudent(s_list);
			break;
		case EXIT :
			// 프로그램 종료
			exit(1);
			break;
		default:
			// 예외처리
			cout << " 잘못 입력하셨습니다 " << endl;
			return 0;
		}
	}
}