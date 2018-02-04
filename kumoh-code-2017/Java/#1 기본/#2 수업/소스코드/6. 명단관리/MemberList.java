package 명단관리;

public class MemberList
{
	final int MAX_MEMBER = 10;
	
	private Member[] member_list;
	private int count;
	
	Member getMemberList(int index) { return member_list[index]; }
	int getCount() { return count; }
	
	public MemberList()
	{
		member_list = new Member[MAX_MEMBER];
		count = 0;
	}
	
	void insertMember(Member mp)
	{
		member_list[count] = mp;
		count++;
	}
	
	void deleteMember(int index)
	{
		member_list[index] = member_list[index + 1];
		count--;
	}
	
	void updateMember(int index, Member mp)
	{
		member_list[index] = mp;
	}
}
