#pragma once
#include "Member.h"

class MemberList
{
private:
	Member member_list[MAX_MEMBERS]; // 명단을 담을 명단부
	int count;
public:
	MemberList() { count = 0; }
	~MemberList() {}
	Member getMemberList(int index) { return member_list[index]; }

	int findMember(string id); // 명단 검색
	void insertMember(); // 명단 등록
	void deleteMember(); // 명단 삭제
	void updateMember(); // 명단 수정
	void displayMember(); // 명단 출력
};