#pragma once
#include "common.h"
#include "Student.h"
#include "StudentList.h"

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}
	// 파일 불러오기
	void loadStudent(string fileName, StudentList& s_list);
	// 파일 저장
	void saveStudent(string fileName, StudentList& s_list);
};
