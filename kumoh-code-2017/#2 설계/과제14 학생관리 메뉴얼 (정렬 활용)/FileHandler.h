#pragma once
#include "common.h"
#include "Student.h"
#include "StudentList.h"

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}
	// ���� �ҷ�����
	void loadStudent(string fileName, StudentList& s_list);
	// ���� ����
	void saveStudent(string fileName, StudentList& s_list);
};
