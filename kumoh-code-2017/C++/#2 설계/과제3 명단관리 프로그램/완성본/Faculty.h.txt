#pragma once
#include "Member.h"

class Faculty : public Member
{
	// 전공분야
	int major;
	// 최종학위
	string degree;
public:
	Faculty() {}
	Faculty(string id, string name, string department, int major, string degree) : Member(id, name, department)
	{
		this->major = major;
		this->degree = degree;
	}
	~Faculty() {}

	// 출력함수
	void putMember() { cout << endl << " ID : " << id << endl << " 성명 : " << name << endl << " 소속학과 : " << department << endl << " 전공분야 : " << major << endl << " 최종학위 : " << degree << endl; }
};