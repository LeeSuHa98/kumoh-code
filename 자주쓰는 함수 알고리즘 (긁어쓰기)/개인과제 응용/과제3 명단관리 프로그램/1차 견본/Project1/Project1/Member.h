#pragma once
#include <iostream>
#include <string>

const int MAX_MEMBERS = 100;

using namespace std;

class Member
{
protected:
	string id;
	string name; // 성명
	string department; // 부서
	int memberType;
public:
	Member() {}
	Member(string id, string name, string department, int memberType)
	{
		this->id = id;
		this->name = name;
		this->department = department;
		this->memberType = memberType;
	}
	~Member() {}

	string getId() { return id; }
	string getName() { return name; }
	string getDepartment() { return department; }
	int getMemberType() { return memberType; }

	// Faculty
	virtual int getMajor() { return 0; }
	virtual int getDegree() { return 0; }
	// Staff
	virtual int getRank() { return 0; }
	virtual string getDuty() { return 0; }

};