#pragma once
#include "Student.h"

class Employee
{
protected:
	string name; // �̸�
	int id; // �й�
	string job; // �����
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
		cout << " �̸� : " << name << endl;
		cout << " �й� : " << id << endl;
		cout << " ���� : " << job << endl;
	}
};