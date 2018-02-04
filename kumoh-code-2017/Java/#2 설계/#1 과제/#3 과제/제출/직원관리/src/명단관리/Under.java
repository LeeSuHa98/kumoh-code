package 명단관리;

public class Under extends Student
{
	private String circle;
	
	Under(String id, String type, String name, int grade, String advisor, String address, double credit, String circle)
	{
		super(id, type, name, grade, advisor, address, credit);
		this.circle = circle;
	}
	
	public void show()
	{
		System.out.println(id + ", " + type + ", " + name + ", " + grade + ", " + advisor + ", " + address + ", " + credit + ", " + circle);
	}
	
	public String getShowOfStringData()
	{
		return id + ", " + type + ", " + name + ", " + Integer.toString(grade) + ", " + advisor + ", " + address + ", " + Double.toString(credit) +", " + circle;
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
