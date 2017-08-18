#pragma once
#include "Member.h"
#include "MemberList.h"
#include "ioHandler.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}
	
	// 명단 검색
	int findMember(MemberList& m_list, string id);
	// 명단 등록
	void registerMember(MemberList& m_list);
	// 명단 삭제
	void unregisterMember(MemberList& m_list);
	// 명단 수정
	void changeMember(MemberList& m_list);
	// 명단 출력
	void displayMember(MemberList& m_list);
};