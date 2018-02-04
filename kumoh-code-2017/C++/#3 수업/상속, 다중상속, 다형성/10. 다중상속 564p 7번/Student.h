#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
	string name; // 이름
	int id; // 학번
	string major; // 학과
	int grade; // 학년
	int credit; // 이수학점
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