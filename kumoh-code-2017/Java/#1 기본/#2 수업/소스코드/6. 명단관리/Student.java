package ��ܰ���;

public class Student extends Member
{
	protected String advisor; //��������
	public Student(String id, String name, String department, String advisor)
	{
		super(id, name, department);
		// TODO Auto-generated constructor stub
		this.advisor = advisor;
	}
	
	public void putMember(){}
}
