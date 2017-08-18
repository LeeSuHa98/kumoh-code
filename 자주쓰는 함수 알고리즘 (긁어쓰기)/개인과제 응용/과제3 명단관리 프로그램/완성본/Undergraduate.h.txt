#pragma once
#include "Student.h"

class Undergraduate : public Student
{
	// 학년
	int grade;
public:
	Undergraduate() {}
	Undergraduate(string id, string name, string department, int grade, string advisor) : Student(id, name, department, advisor)
	{
		this->grade = grade;
	}
	~Undergraduate() {}

	// 출력함수
	void putMember() { cout << endl << " ID : " << id << endl << " 성명 : " << name << endl << " 소속학과 : " << department << endl << " 학년 : " << grade << endl << " 지도교수 : " << advisor << endl; }
};