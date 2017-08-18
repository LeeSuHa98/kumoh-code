#pragma once
#include "Member.h"

class Undergraduate : public Member
{
	int grade; // 학년
	string advisor; // 지도교수
public:
	Undergraduate() {}
	Undergraduate(string id, string name, string department, int memberType, int grade, string advisor)
	{
		this->id = id;
		this->name = name;
		this->department = department;
		this->memberType = memberType;
		this->grade = grade;
		this->advisor = advisor;
	}
	~Undergraduate() {}

	int getGrade() { return grade; }
	string getAdvisor() { return advisor; }
};
