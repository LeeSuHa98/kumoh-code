#pragma once
#include "StudentList.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	// 학생 검색
	int findStudent(StudentList& s_list, int id);
	// 학생 등록
	void registerStudent(StudentList& s_list);
	// 학생 삭제
	void unregisterStudent(StudentList& s_list);
	// 학생 수정
	void changeStudent(StudentList& s_list);
	// 학생 출력
	void displayStudent(StudentList s_list);
};