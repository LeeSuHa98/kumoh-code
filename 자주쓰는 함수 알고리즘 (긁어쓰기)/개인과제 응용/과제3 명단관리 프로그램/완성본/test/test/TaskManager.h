#pragma once
#include "Member.h"
#include "MemberList.h"
#include "ioHandler.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}
	
	// ��� �˻�
	int findMember(MemberList& m_list, string id);
	// ��� ���
	void registerMember(MemberList& m_list);
	// ��� ����
	void unregisterMember(MemberList& m_list);
	// ��� ����
	void changeMember(MemberList& m_list);
	// ��� ���
	void displayMember(MemberList& m_list);
};