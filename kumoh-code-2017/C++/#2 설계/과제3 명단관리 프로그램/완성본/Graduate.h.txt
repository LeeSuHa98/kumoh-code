#pragma once
#include "Student.h"

class Graduate : public Student
{
	// 학위과정
	string degree;
	// 전공분야
	int major;
public:
	Graduate() {}
	Graduate(string id, string name, string department, string degree, int major, string advisor) : Student(id, name, department, advisor)
	{
		this->degree = degree;
		this->major = major;
	}
	~Graduate() {}

	// 출력함수
	void putMember() { cout << endl << " ID : " << id << endl << " 성명 : " << name << endl << " 소속학과 : " << department << endl << " 학위과정 : " << degree << endl << " 전공분야 : " << major << endl << " 지도교수 : " << advisor << endl; }
};