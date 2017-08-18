#pragma once
#include "Student.h"

class Graduate : public Student
{
	// ��������
	string degree;
	// �����о�
	int major;
public:
	Graduate() {}
	Graduate(string id, string name, string department, string degree, int major, string advisor) : Student(id, name, department, advisor)
	{
		this->degree = degree;
		this->major = major;
	}
	~Graduate() {}

	// ����Լ�
	void putMember() { cout << endl << " ID : " << id << endl << " ���� : " << name << endl << " �Ҽ��а� : " << department << endl << " �������� : " << degree << endl << " �����о� : " << major << endl << " �������� : " << advisor << endl; }
};