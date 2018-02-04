#pragma once
#include "Member.h"

class MemberList
{
private:
	// 명단을 담을 배열
	Member* member_list[MAX_MEMBERS];
	int count;
public:
	MemberList() { count = 0; }
	~MemberList() {}

	Member* getMemberList(int index) { return member_list[index]; }
	int getCount() { return count; }
	void plusCount() { count++; }
	void minusCount() { count--; }

	void insertMember(Member* mp);
	void deleteMember(int index);
	void updateMember(int index, Member* mp);
};