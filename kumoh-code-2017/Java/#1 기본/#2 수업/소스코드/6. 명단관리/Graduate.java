package ��ܰ���;

public class Graduate extends Student
{
	private String degree; //��������
	private int major; //�����о�
	
	public Graduate(String id, String name, String department, String degree, int major, String advisor)
	{
		super(id, name, department, advisor);
		// TODO Auto-generated constructor stub
		this.degree = degree;
		this.major = major;
	}
	
	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("���� : " + name);
		System.out.println("�Ҽ��а� : " + department);
		System.out.println("�������� : " + degree);
		System.out.println("�����о� : " + major);
		System.out.println("�������� : " + advisor);
	}
}
