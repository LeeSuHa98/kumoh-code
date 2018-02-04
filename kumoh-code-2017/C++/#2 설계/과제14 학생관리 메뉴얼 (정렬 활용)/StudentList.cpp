#include "StudentList.h"

int StudentList::findStudent(int id)
{
	for (int i = 0; i < count; i++)
	{
		if (id == studentList[i].getId())	// 객체 배열 내의 학생id key값 검색
		{
			return i;
		}
	}
	cout << "잘못 입력하셨습니다. 다시 입력하시오." << endl;
}

void StudentList::insertStudent(Student s)
{
	studentList[count] = s;	// 생성된 객체를 배열에 삽입
	count++;	// 배열의 다음 공간으로 이동
}

void StudentList::registerStudentRecord()
{
	int id;
	string name;
	int kor;
	int math;
	int eng;

	while (1)
	{
		if (isFlag() == false)
		{
			break;
		}
		else
		{
			cout << "학생의 인적사항을 입력하시오" << endl;
			cout << "학번 : ";
			cin >> id;
			cout << "이름 : ";
			cin >> name;
			cout << "학생의 성적을 입력하시오" << endl;
			cout << "국어 : ";
			cin >> kor;
			cout << "수학 : ";
			cin >> math;
			cout << "영어 : ";
			cin >> eng;

			Student s(id, name, kor, math, eng);	// 학생 Entity 생성자

			insertStudent(s);	// 학생 Entity의 정보를 List 객체 배열에 할당;
		}

		cout << "학번, 이름, 성적 입력 후 더 입력?(y/n)" << endl;

		char select;
		cin >> select;

		switch (select)
		{
		case 'y':
		case 'Y':
			flag = true;
			break;
		case 'n':
		case 'N':
			flag = false;
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}

	flag = true;	// 메뉴에서 재등록을 위한 초기화
}

void StudentList::averageStudentRecord()
{
	for (int i = 0; i < count; i++)
	{
		cout << "학번 : " << studentList[i].getId() << endl;
		cout << "이름 : " << studentList[i].getName() << endl;
		cout << "평균 성적 : " << studentList[i].getAvgRecord() << endl;
		cout << endl;
	}
}

void StudentList::sortByStudentRecordWithId()
{
	for (int i = 0; i < count - 1; i++)   // 선택정렬
	{
		int id1 = studentList[i].getId();	// 객체 배열의 비교할 첫번째 id를 변수에 할당
		for (int j = i + 1; j < count; j++)
		{
			int id2 = studentList[j].getId();	//	객체 배열의 비교할 두번째 id를 변수에 할당
			if (id1 >= id2)	// 할당된 변수끼리 비교
			{	// Swap
				Student temp;
				temp = studentList[i];
				studentList[i] = studentList[j];
				studentList[j] = temp;
			}
		}
	}
}

void StudentList::sortByStudentRecordWithGrade()
{
	for (int i = 0; i < count - 1; i++)   // 선택정렬
	{
		int avg1 = studentList[i].getAvgRecord();	// 객체 배열의 비교할 첫번째 id를 변수에 할당
		for (int j = i + 1; j < count; j++)
		{
			int avg2 = studentList[j].getAvgRecord();	//	객체 배열의 비교할 두번째 id를 변수에 할당
			if (avg1 <= avg2)	// 할당된 변수끼리 비교
			{	// Swap
				Student temp;
				temp = studentList[i];
				studentList[i] = studentList[j];
				studentList[j] = temp;
			}
		}
	}
}

void StudentList::searchByStudentId()
{
	int id;

	cout << "학생의 학번을 검색합니다." << endl;
	
	cout << "검색할 학생의 학번을 입력하시오 : ";
	cin >> id;

	selectDisplayStudent(findStudent(id));	// 탐색한 학생을 출력
}

void StudentList::selectDisplayStudent(int index)
{	// 인자로 넘겨진 학생의 데이터 정보를 출력
	cout << "학번 : " << studentList[index].getId() << endl;
	cout << "이름 : " << studentList[index].getName() << endl;
	cout << "국어 성적 : " << studentList[index].getKor() << endl;
	cout << "수학 성적 : " << studentList[index].getMath() << endl;
	cout << "영어 성적 : " << studentList[index].getEng() << endl;
	cout << "평균 성적 : " << studentList[index].getAvgRecord() << endl;
}

void StudentList::allDisplayStudent()
{
	for (int i = 0; i < count; i++)	// count된 모든 학생의 정보를 출력
	{
		cout << "학번 : " << studentList[i].getId() << endl;
		cout << "이름 : " << studentList[i].getName() << endl;
		cout << "국어 성적 : " << studentList[i].getKor() << endl;
		cout << "수학 성적 : " << studentList[i].getMath() << endl;
		cout << "영어 성적 : " << studentList[i].getEng() << endl;
		cout << "평균 성적 : " << studentList[i].getAvgRecord() << endl;
	}
}