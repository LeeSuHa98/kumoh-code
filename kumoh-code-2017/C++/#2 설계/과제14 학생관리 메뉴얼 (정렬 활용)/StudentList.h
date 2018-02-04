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

	// �л� �˻�
	int findStudent(int id);
	// �л� ����
	void insertStudent(Student s);
	// ���� �Է�
	void registerStudentRecord();
	// ���
	void averageStudentRecord();
	// ����(�й� ��)
	void sortByStudentRecordWithId();
	// ����(���� ��)
	void sortByStudentRecordWithGrade();
	// �˻�(�й�)
	void searchByStudentId();
	// ���� ���
	void selectDisplayStudent(int index);
	// ��ü ���
	void allDisplayStudent();
};
