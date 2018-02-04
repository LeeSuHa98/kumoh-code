package 명단관리;

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
		System.out.println("과정 : " + this.curriculum);
		System.out.println("성명 : " + this.name);
		System.out.println("학년 : " + this.grade);
		System.out.println("지도교수 : " + this.advisor);
		System.out.println("주소 : " + this.address);
		System.out.println("동아리 : " + circle);
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
