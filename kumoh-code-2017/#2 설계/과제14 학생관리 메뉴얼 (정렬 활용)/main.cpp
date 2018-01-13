#include "common.h"
#include "Student.h"
#include "StudentList.h"
#include "FileHandler.h"

int main()
{
	// 객체 선언
	StudentList s_list;
	FileHandler fh;

	while (1)
	{
		cout << "---------- 학생관리 메뉴                 ----------" << endl;
		cout << "---------- 1. 성적입력(국어, 수학, 영어) ----------" << endl;
		cout << "---------- 2. 파일로 저장                ----------" << endl;
		cout << "---------- 3. 파일로부터 읽기            ----------" << endl;
		cout << "---------- 4. 통계                       ----------" << endl;
		cout << "---------- 5. 정렬(학번 순, 오름차순)    ----------" << endl;
		cout << "---------- 6. 정렬(성적 순, 내림차순)    ----------" << endl;
		cout << "---------- 7. 검색(학번)                 ----------" << endl;
		cout << "---------- 8. 전체 출력                  ----------" << endl;
		cout << "---------- 9. 종료                       ----------" << endl;
		cout << "선택 : ";

		int select;
		cin >> select;

		switch (select)
		{	// 객체의 Method 호출
		case 1:	// 성적 입력
			s_list.registerStudentRecord();
			break;
		case 2:	// 파일로 저장
			fh.saveStudent("Student.txt", s_list);
			break;
		case 3:	// 파일로부터 읽기
			fh.loadStudent("Student.txt", s_list);
			break;
		case 4:	// 통계
			s_list.averageStudentRecord();
			break;
		case 5:	// 정렬(학번 순)
			s_list.sortByStudentRecordWithId();
			break;
		case 6:	// 정렬(성적 순)
			s_list.sortByStudentRecordWithGrade();
			break;
		case 7:	// 검색(학번)
			s_list.searchByStudentId();
			break;
		case 8:	// 전체 출력
			s_list.allDisplayStudent();
			break;
		case 9:	// 종료
			exit(1);
			break;
		}
	}

	system("pause");
	return 0;
}