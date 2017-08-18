#include <iostream>
#include "Member.h"
#include "MemberList.h"

using namespace std;

int main()
{
	MemberList m_list;
	
	while (true)
	{
		// 메뉴
		cout << "------ 명단관리 프로그램 ------" << endl;
		cout << "------ 1. 명단 정보 등록 ------" << endl;
		cout << "------ 2. 명단 정보 삭제 ------" << endl;
		cout << "------ 3. 명단 정보 수정 ------" << endl;
		cout << "------ 4. 명단 정보 출력 ------" << endl;
		cout << "------ 5. 프로그램 종료  ------" << endl;
		cout << "-------------------------------" << endl;

		int select;
		cin >> select;

		// 종료
		switch (select)
		{
		case 1:
			// 등록
			m_list.insertMember();
			break;
		case 2:
			// 삭제
			m_list.deleteMember();
			break;
		case 3:
			// 수정
			m_list.updateMember();
			break;
		case 4:
			// 출력
			m_list.displayMember();
			break;
		case 5:
			// 프로그램 종료
			exit(1);
		default:
			cout << " 잘못 입력하셨습니다 " << endl;
			return 0;
		}
	}
}