#pragma once
#include "Student.h"

using namespace std;

class StudentList
{
private:
	Student* student_list;
	int count;
public:
	StudentList() { student_list = new Student[MAX_STUDENTS]; count = 0; }
	~StudentList() {}

	Student getStudentList(int index) { return student_list[index]; }
	int getCount() { return count; }

	void insertStudent(Student s);
	void deleteStudent(int index);
	void updateStudent(int index, Student s);
};