package ��ܰ���;

public class Graduate extends Student
{
	protected String major;
	
	Graduate(String curriculum, String name, int grade, String advisor, String address, String major)
	{
		super(curriculum, name, grade, advisor, address);
		this.major = major;
	}
	
	public void show()
	{
		System.out.println("���� : " + this.curriculum);
		System.out.println("�̸� : " + this.name);
		System.out.println("�г� : " + this.grade);
		System.out.println("�������� : " + this.advisor);
		System.out.println("�ּ� : " + this.address);
		System.out.println("�����о� : " + major);
		System.out.println();
	}
	
	public void changeMajor(String major) throws MyException
	{
		if(major.isEmpty())
		{
			int code = -400;
			String description = "Null Object Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else if(major == "") 
		{
			int code = -100;
			String description = "Major Name - Empty Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else
		{
			this.major = major;
		}
	}
	
	
}
