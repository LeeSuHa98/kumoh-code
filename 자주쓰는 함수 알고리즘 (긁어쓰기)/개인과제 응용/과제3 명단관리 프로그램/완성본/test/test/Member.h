#pragma once
#include <iostream>
#include <string>

const int MAX_MEMBERS = 100;

enum Menus {INSERT = 1, DELETE, UPDATE, DISPLAY, EXIT};

using namespace std;

class Member
{
protected:
	string id;
	string name;
	string department;

public:
	Member() {}
	Member(string id, string name, string department)
	{
		this->id = id;
		this->name = name;
		this->department = department;
	}
	~Member() {}

	virtual void putMember() {}

	string getId() { return id; }
};