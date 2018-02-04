#pragma once
#include "Member.h"

class Graduate : public Member
{
	int degree; // 학위과정
	int major; // 전공분야
	string advisor; // 지도교수
public:
	Graduate() {}
	Graduate(string id, string name, string department, int memberType, int degree, int major, string advisor)
	{
		this->id = id;
		this->name = name;
		this->department = department;
		this->memberType = memberType;
		this->degree = degree;
		this->major = major;
		this->advisor = advisor;
	}
	~Graduate() {}

	int getDegree() { return degree; }
	int getMajor() { return major; }
	string getAdvisor() { return advisor; }
};