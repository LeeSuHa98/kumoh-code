#pragma once
#include "Student.h"

class Graduate : public Student
{
	string assistant; // ��������
	int bursary; // ���б�
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
		cout << " �̸� : " << name << endl;
		cout << " �й� : " << id << endl;
		cout << " �а� : " << major << endl;
		cout << " �г� : " << grade << endl;
		cout << " �̼����� : " << credit << endl;
		cout << " �������� : " << assistant << endl;
		cout << " ���б� : " << bursary << endl;
	}
};