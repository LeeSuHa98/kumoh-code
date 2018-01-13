#pragma once
#include "common.h"

class Student
{
private:
	int kor;
	int math;
	int eng;
public:
	Student() {}
	Student(int kor, int math, int eng)
	{
		this->kor = kor;
		this->math = math;
		this->eng = eng;
	}
	~Student() {}

	friend bool operator < (Student& s1, Student& s2);
	friend bool operator > (const Student& s1, const Student& s2);
	friend bool operator <= (Student& s1, Student& s2);
	friend bool operator >= (Student& s1, Student& s2);
	friend bool operator == (Student& s1, Student& s2);
	friend ofstream& operator <<(ofstream& ofs, Student& s);
};