package ��ܰ���;

public class Staff extends Member
{
	private int rank; //����
	private String duty; //������
	
	public Staff(String id, String name, String department, int rank, String duty)
	{
		super(id, name, department);
		// TODO Auto-generated constructor stub
		this.rank = rank;
		this.duty = duty;
	}

	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("���� : " + name);
		System.out.println("�ҼӺμ� : " + department);
		System.out.println("���� : " + rank);
		System.out.println("������ : " + duty);
	}
}
