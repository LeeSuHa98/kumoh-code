#pragma once
#include "Member.h"

class Faculty : public Member
{
	// �����о�
	int major;
	// ��������
	string degree;
public:
	Faculty() {}
	Faculty(string id, string name, string department, int major, string degree) : Member(id, name, department)
	{
		this->major = major;
		this->degree = degree;
	}
	~Faculty() {}

	// ����Լ�
	void putMember() { cout << endl << " ID : " << id << endl << " ���� : " << name << endl << " �Ҽ��а� : " << department << endl << " �����о� : " << major << endl << " �������� : " << degree << endl; }
};