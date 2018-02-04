#pragma once
#include "Member.h"

class MemberList
{
private:
	Member member_list[MAX_MEMBERS]; // ����� ���� ��ܺ�
	int count;
public:
	MemberList() { count = 0; }
	~MemberList() {}
	Member getMemberList(int index) { return member_list[index]; }

	int findMember(string id); // ��� �˻�
	void insertMember(); // ��� ���
	void deleteMember(); // ��� ����
	void updateMember(); // ��� ����
	void displayMember(); // ��� ���
};