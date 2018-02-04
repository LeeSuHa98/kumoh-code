#pragma once
#include "Member.h"

class Faculty : public Member
{
	int major; // 전공분야
	int degree; // 최종학위
public:
	Faculty() {}
	Faculty(string id, string name, string department, int memberType, int major, int degree)
	{
		this->id = id;
		this->name = name;
		this->department = department;
		this->memberType = memberType;
		this->major = major;
		this->degree = degree;
	}
	~Faculty() {}

	int getMajor() { return major; }
	int getDegree() { return degree; }
};