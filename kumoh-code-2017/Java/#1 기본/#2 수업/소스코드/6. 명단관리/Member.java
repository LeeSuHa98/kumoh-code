package ��ܰ���;

public abstract class Member
{
	protected String id; //�й�
	protected String name; //�̸�
	protected String department; //�а�
	
	public Member(String id, String name, String department)
	{
		this.id = id;
		this.name = name;
		this.department = department;
	}
	
	public abstract void putMember();
	
	String getId() { return id; }
}
