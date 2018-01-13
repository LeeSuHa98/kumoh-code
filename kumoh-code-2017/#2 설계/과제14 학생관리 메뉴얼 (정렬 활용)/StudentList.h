#pragma once
#include "common.h"
#include "Student.h"

class StudentList
{
private:
	Student* studentList;
	int count;
	bool flag;
public:
	StudentList() 
	{
		studentList = new Student[MAX_STUDENT];
		count = 0;
		flag = true;
	}
	~StudentList() {}

	Student getStudentList(int index) { return studentList[index]; }
	int getCount() { return count; }
	bool isFlag() { return flag; }

	// 학생 검색
	int findStudent(int id);
	// 학생 삽입
	void insertStudent(Student s);
	// 성적 입력
	void registerStudentRecord();
	// 통계
	void averageStudentRecord();
	// 정렬(학번 순)
	void sortByStudentRecordWithId();
	// 정렬(성적 순)
	void sortByStudentRecordWithGrade();
	// 검색(학번)
	void searchByStudentId();
	// 선택 출력
	void selectDisplayStudent(int index);
	// 전체 출력
	void allDisplayStudent();
};
