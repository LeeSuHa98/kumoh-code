#include "TaskManager.h"

int TaskManager::findMember(MemberList& m_list, string id)
{
	for (int i = 0; i < m_list.getCount(); i++)
	{
		if (id == m_list.getMemberList(i)->getId())
		{
			return i;
		}
	}
}

void TaskManager::registerMember(MemberList& m_list)
{
	ioHandler ioh;

	ioh.putString(" ����� ������ ����մϴ� ");
	
	char member_type = ioh.insertMemberType();
	Member* mp = ioh.getMember(member_type);

	m_list.insertMember(mp);
	m_list.plusCount();
}

void TaskManager::unregisterMember(MemberList& m_list)
{
	ioHandler ioh;

	ioh.putString(" ����� ������ �����մϴ� ");

	string id = ioh.getString(" ������ ����� ID�� �Է��Ͻÿ� : ");

	for (int i = findMember(m_list, id); i < m_list.getCount(); i++)
	{
		m_list.deleteMember(i);
	}

	m_list.minusCount();
}

void TaskManager::changeMember(MemberList& m_list)
{
	ioHandler ioh;

	ioh.putString(" ����� ������ �����մϴ� ");

	char member_type = ioh.insertMemberType();
	string id = ioh.getString(" ������ ����� ID�� �Է��Ͻÿ� : ");

	Member* mp = ioh.getMember(member_type);
	m_list.updateMember(findMember(m_list, id), mp);
}

void TaskManager::displayMember(MemberList& m_list)
{
	ioHandler ioh;

	ioh.putString(" ����� ������ ����մϴ� ");

	for (int i = 0; i < m_list.getCount(); i++)
	{
		Member* mp = m_list.getMemberList(i);
		mp->putMember();
	}
}