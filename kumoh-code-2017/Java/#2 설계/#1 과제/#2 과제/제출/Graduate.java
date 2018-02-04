package 명단관리;

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
		System.out.println("과정 : " + this.curriculum);
		System.out.println("이름 : " + this.name);
		System.out.println("학년 : " + this.grade);
		System.out.println("지도교수 : " + this.advisor);
		System.out.println("주소 : " + this.address);
		System.out.println("연구분야 : " + major);
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
