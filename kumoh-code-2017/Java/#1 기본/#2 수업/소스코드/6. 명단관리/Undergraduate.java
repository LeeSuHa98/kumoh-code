package ��ܰ���;

public class Undergraduate extends Student
{
	private int grade; //�г�
	public Undergraduate(String id, String name, String department, int grade, String advisor)
	{
		super(id, name, department, advisor);
		// TODO Auto-generated constructor stub
		this.grade = grade;
	}
	
	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("���� : " + name);
		System.out.println("�Ҽ��а� : " + department);
		System.out.println("�г� : " + grade);
		System.out.println("�������� : " + advisor);
	}
}
