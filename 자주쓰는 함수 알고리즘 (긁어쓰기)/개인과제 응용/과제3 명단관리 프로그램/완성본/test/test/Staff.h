#pragma once
#include "Member.h"

class Staff : public Member
{
	// 직급
	int rank;
	// 담당업무
	string duty;
public:
	Staff() {}
	Staff(string id, string name, string department, int rank, string duty) : Member(id, name, department)
	{
		this->rank = rank;
		this->duty = duty;
	}
	~Staff() {}

	// 출력함수
	void putMember() { cout << endl << " ID : " << id << endl << " 성명 : " << name << endl << " 소속부서 : " << department << endl << " 직급 : " << rank << endl << " 담당업무 : " << duty << endl; }
};