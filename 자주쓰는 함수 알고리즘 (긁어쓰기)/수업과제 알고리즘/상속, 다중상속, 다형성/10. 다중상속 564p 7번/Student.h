#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
	string name; // �̸�
	int id; // �й�
	string major; // �а�
	int grade; // �г�
	int credit; // �̼�����
public:
	Student() {}
	Student(string name, int id, string major, int grade, int credit)
	{
		this->id = id;
		this->name = name;
		this->major = major;
		this->grade = grade;
		this->credit = credit;
	}
	~Student() {}
};