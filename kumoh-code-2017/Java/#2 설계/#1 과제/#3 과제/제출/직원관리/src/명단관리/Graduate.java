package 명단관리;

public class Graduate extends Student
{
	protected String major;
	
	Graduate(String id, String type, String name, int grade, String advisor, String address, double credit, String major)
	{
		super(id, type, name, grade, advisor, address, credit);
		this.major = major;
	}
	
	public void show()
	{
		System.out.println(id + ", " + type + ", " + name + ", " + grade + ", " + advisor + ", " + address + ", " + credit + ", " + major);
	}
	
	public String getShowOfStringData()
	{
		return id + ", " + type + ", " + name + ", " + Integer.toString(grade) + ", " + advisor + ", " + address + ", " + Double.toString(credit) + ", " + major;
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
