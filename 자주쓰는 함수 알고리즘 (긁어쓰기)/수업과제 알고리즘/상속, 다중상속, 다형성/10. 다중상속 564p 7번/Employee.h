#pragma once
#include "Student.h"

class Employee
{
protected:
	string name; // 이름
	int id; // 학번
	string job; // 직장명
public:
	Employee() {}
	Employee(string name, int id, string job)
	{
		this->name = name;
		this->id = id;
		this->job = job;
	}
	~Employee() {}

	void print()
	{
		cout << " 이름 : " << name << endl;
		cout << " 학번 : " << id << endl;
		cout << " 직업 : " << job << endl;
	}
};