#pragma once
#include "Member.h"

class Student : public Member
{
protected:
	string advisor;
public:
	Student() {}
	Student(string id, string name, string department, string advisor) : Member(id, name, department)
	{
		this->advisor = advisor;
	}
	virtual ~Student() {}
};