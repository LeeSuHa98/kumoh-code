package ��ܰ���;

public class Faculty extends Member
{
	private int major; //�����о�
	private String degree; //��������
	
	public Faculty(String id, String name, String department,int major, String degree)
	{
		super(id, name, department);
		// TODO Auto-generated constructor stub
		this.major = major;
		this.degree = degree;
	}

	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("���� : " + name);
		System.out.println("�Ҽ��а� : " + department);
		System.out.println("�����о� : " + major);
		System.out.println("�������� : " + degree);
	}
}
