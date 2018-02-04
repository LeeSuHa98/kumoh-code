#pragma once
#include "Student.h"

class Graduate : public Student
{
	string assistant; // 조교유형
	int bursary; // 장학금
public:
	Graduate() {}
	Graduate(string name, int id, string major, int grade, int credit,string assistant, int bursary) : Student(name,id,major,grade,credit)
	{
		this->assistant = assistant;
		this->bursary = bursary;
	}
	~Graduate() {}

	void print()
	{
		cout << " 이름 : " << name << endl;
		cout << " 학번 : " << id << endl;
		cout << " 학과 : " << major << endl;
		cout << " 학년 : " << grade << endl;
		cout << " 이수학점 : " << credit << endl;
		cout << " 조교유형 : " << assistant << endl;
		cout << " 장학금 : " << bursary << endl;
	}
};