package ��ܰ���;

abstract public class Student
{
	protected String id;
	protected String type;
	protected String name;
	protected int grade;
	protected String advisor;
	protected String address;
	protected double credit;
	
	Student(String name, int grade, String advisor, String address)
	{
		this.name = name;
		this.grade = grade;
		this.advisor = advisor;
		this.address = address;
	}
	Student(String id, String type, String name, int grade, String advisor, String address, double credit)
	{
		this.id = id;
		this.type = type;
		this.name = name;
		this.grade = grade;
		this.advisor = advisor;
		this.address = address;
		this.credit = credit;
	}
	
	public void changeAddress(String address) throws MyException
	{
		if(address.isEmpty())
		{
			int code = -400;
			String description = "Null Object Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else 
		{
			this.address = address;
		}
	}
	
//	public void studentShow()
//	{
//		System.out.println("���� : " + name);
//		System.out.println("�г� : " + grade);
//		System.out.println("�������� : " + advisor);
//		System.out.println("�ּ� : " + address);
//		System.out.println();
//	}
//	
	public abstract void show();
	public abstract String getShowOfStringData();
}
