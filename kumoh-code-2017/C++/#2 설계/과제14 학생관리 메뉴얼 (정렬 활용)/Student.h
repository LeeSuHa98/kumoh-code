#pragma once
#include "common.h"

class Student
{
private:
	int id;	// �й�
	string name;	// �̸�
	int kor;	// ���� ����
	int math;	// ���� ����
	int eng;	// ���� ����
public:
	Student() {}
	Student(int id, string name, int kor, int math, int eng)
	{
		this->id = id;
		this->name = name;
		this->kor = kor;
		this->math = math;
		this->eng = eng;
	}
	~Student() {}

	int getId() { return id; }
	string getName() { return name; }
	int getKor() { return kor; }
	int getMath() { return math; }
	int getEng() { return eng; }
	double getAvgRecord() { return (kor + math + eng) / 3; }
};