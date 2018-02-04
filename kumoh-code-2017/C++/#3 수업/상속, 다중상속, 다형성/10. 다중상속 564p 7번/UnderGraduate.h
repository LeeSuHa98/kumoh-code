#pragma once
#include "Student.h"

class UnderGraduate : public Student
{
	string club; // 동아리명
public:
	UnderGraduate() {}
	UnderGraduate(string name, int id, string major, int grade, int credit, string club) : Student(name,id,major,grade,credit)
	{
		this->club = club;
	}
	~UnderGraduate() {}

	void print()
	{
		cout << " 이름 : " << name << endl;
		cout << " 학번 : " << id << endl;
		cout << " 학과 : " << major << endl;
		cout << " 학년 : " << grade << endl;
		cout << " 장학금 : " << credit << endl;
		cout << " 동아리 : " << club << endl;
	}
};