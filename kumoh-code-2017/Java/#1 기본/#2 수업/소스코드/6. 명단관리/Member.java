package 명단관리;

public abstract class Member
{
	protected String id; //학번
	protected String name; //이름
	protected String department; //학과
	
	public Member(String id, String name, String department)
	{
		this.id = id;
		this.name = name;
		this.department = department;
	}
	
	public abstract void putMember();
	
	String getId() { return id; }
}
