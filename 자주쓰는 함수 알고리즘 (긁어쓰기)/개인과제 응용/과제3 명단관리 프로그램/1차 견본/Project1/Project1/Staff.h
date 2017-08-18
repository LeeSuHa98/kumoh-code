#pragma once
#include "Member.h"

class Staff : public Member
{
	int rank; // 직급
	string duty; // 담당업무
public:
	Staff() {}
	Staff(string id, string name, string department, int memberType, int rank, string duty)
	{
		this->id = id;
		this->name = name;
		this->department = department;
		this->memberType = memberType;
		this->rank = rank;
		this->duty = duty;
	}
	~Staff() {}

	int getRank() { return rank; }
	string getDuty() { return duty;}
};