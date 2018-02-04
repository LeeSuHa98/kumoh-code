package ��ܰ���;

public class IndustryGraduate extends Graduate implements Employee
{
	private String company;
	private String department;
	private String position;
	
	IndustryGraduate(String curriculum, String name, int grade, String advisor, String address, String major, String company, String department, String position)
	{
		super(curriculum, name, grade, advisor, address, major);
		this.company = company;
		this.department = department;
		this.position = position;
	}
	
	public void show()
	{
		System.out.println("���� : " + this.curriculum);
		System.out.println("���� : " + this.name);
		System.out.println("�г� : " + this.grade);
		System.out.println("�������� : " + this.advisor);
		System.out.println("�ּ� : " + this.address);
		System.out.println("�����о� : " + this.major);
		System.out.println("ȸ�� : " + company);
		System.out.println("�μ� : " + department);
		System.out.println("��å : " + position);
		System.out.println();
	}
	
	public void changePosition(String position) throws MyException
	{
		if(position.isEmpty())
		{
			int code = -400;
			String description = "Null Object Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else if(position == "") 
		{
			int code = -300;
			String description = "Position Name - Empty Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else
		{
			this.position = position;
		}
	}
}
