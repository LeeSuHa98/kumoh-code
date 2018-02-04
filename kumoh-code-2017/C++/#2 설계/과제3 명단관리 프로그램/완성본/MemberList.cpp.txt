#include "MemberList.h"

void MemberList::insertMember(Member* mp)
{
	member_list[count] = mp;
}

void MemberList::deleteMember(int index)
{
	member_list[index] = member_list[index + 1];
}

void MemberList::updateMember(int index, Member* mp)
{
	member_list[index] = mp;
}