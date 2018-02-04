package 명단관리;

public class Student
{
	protected String curriculum;
	protected String name;
	protected int grade;
	protected String advisor;
	protected String address;
	
	Student(String curriculum, String name, int grade, String advisor, String address)
	{
		this.curriculum = curriculum;
		this.name = name;
		this.grade = grade;
		this.advisor = advisor;
		this.address = address;
	}
	Student(String name, int grade, String advisor, String address)
	{
		this.name = name;
		this.grade = grade;
		this.advisor = advisor;
		this.address = address;
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
	
	public void show()
	{
		System.out.println("성명 : " + name);
		System.out.println("학년 : " + grade);
		System.out.println("지도교수 : " + advisor);
		System.out.println("주소 : " + address);
		System.out.println();
	}
}
