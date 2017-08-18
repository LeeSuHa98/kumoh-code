#pragma once
#include "Student.h"

class UnderGraduate : public Student
{
	string club; // ���Ƹ���
public:
	UnderGraduate() {}
	UnderGraduate(string name, int id, string major, int grade, int credit, string club) : Student(name,id,major,grade,credit)
	{
		this->club = club;
	}
	~UnderGraduate() {}

	void print()
	{
		cout << " �̸� : " << name << endl;
		cout << " �й� : " << id << endl;
		cout << " �а� : " << major << endl;
		cout << " �г� : " << grade << endl;
		cout << " ���б� : " << credit << endl;
		cout << " ���Ƹ� : " << club << endl;
	}
};