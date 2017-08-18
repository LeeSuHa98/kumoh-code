#pragma once
#include "Member.h"

class Faculty : public Member
{
	int major; // �����о�
	int degree; // ��������
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