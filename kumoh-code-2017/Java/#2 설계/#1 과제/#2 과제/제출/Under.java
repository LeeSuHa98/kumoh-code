package ��ܰ���;

public class Under extends Student
{
	private String circle;
	
	Under(String curriculum, String name, int grade, String advisor, String address, String circle)
	{
		super(curriculum, name, grade, advisor, address);
		this.circle = circle;
	}
	
	public void show()
	{
		System.out.println("���� : " + this.curriculum);
		System.out.println("���� : " + this.name);
		System.out.println("�г� : " + this.grade);
		System.out.println("�������� : " + this.advisor);
		System.out.println("�ּ� : " + this.address);
		System.out.println("���Ƹ� : " + circle);
		System.out.println();
	}

	public void changeCircle(String circle) throws MyException
	{
		if(circle.isEmpty())
		{
			int code = -400;
			String description = "Null Object Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else if(circle == "") 
		{
			int code = -200;
			String description = "Circle Name - Empty Error";
			
			MyException exception = new MyException(code, description);
			
			throw exception;
		}
		else
		{
			this.circle = circle;
		}
	}
}
