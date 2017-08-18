#pragma once
#include "StudentList.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	// �л� �˻�
	int findStudent(StudentList& s_list, int id);
	// �л� ���
	void registerStudent(StudentList& s_list);
	// �л� ����
	void unregisterStudent(StudentList& s_list);
	// �л� ����
	void changeStudent(StudentList& s_list);
	// �л� ���
	void displayStudent(StudentList s_list);
};