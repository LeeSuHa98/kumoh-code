package 명단관리;

public class TaskManager
{
	public int findMember(MemberList m_list, String id)
	{
		for (int i = 0; i < m_list.getCount(); i++)
		{
			if (id == m_list.getMemberList(i).getId())
			{
				return i;
			}
		}
		return 0;
	}

	public void registerMember(MemberList m_list)
	{
		ioHandler ioh = new ioHandler();

		System.out.println("명단의 정보를 등록합니다 ");
		
		char member_type = ioh.insertMemberType();
		Member mp = ioh.getMember(member_type);
		
		m_list.insertMember(mp);
	}

	public void unregisterMember(MemberList m_list)
	{
		ioHandler ioh = new ioHandler();

		System.out.println("명단의 정보를 삭제합니다 ");

		String id = ioh.getString(" 삭제할 명단의 ID를 입력하시오 : ");

		for (int i = findMember(m_list, id); i < m_list.getCount(); i++)
		{
			m_list.deleteMember(i);
		}
	}

	public void changeMember(MemberList m_list)
	{
		ioHandler ioh = new ioHandler();

		System.out.println("명단의 정보를 수정합니다 ");

		char member_type = ioh.insertMemberType();
		String id = ioh.getString(" 수정할 명단의 ID를 입력하시오 : ");

		Member mp = ioh.getMember(member_type);
		m_list.updateMember(findMember(m_list, id), mp);
	}

	public void displayMember(MemberList m_list)
	{
		System.out.println("명단의 정보를 출력합니다 ");

		for (int i = 0; i < m_list.getCount(); i++)
		{
			Member mp = m_list.getMemberList(i);
			mp.putMember();
		}
	}
}
