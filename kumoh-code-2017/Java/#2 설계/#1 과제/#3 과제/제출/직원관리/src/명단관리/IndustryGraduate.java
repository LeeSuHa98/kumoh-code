package 명단관리;

public class IndustryGraduate extends Graduate implements Employee
{
	private String company;
	private String department;
	private String position;
	
	IndustryGraduate(String id, String type, String name, int grade, String advisor, String address, double credit, String major, String company, String department, String position)
	{
		super(id, type, name, grade, advisor, address, credit, major);
		this.company = company;
		this.department = department;
		this.position = position;
	}
	
	public void show()
	{	
		System.out.println(id + ", " + name + ", " + grade + ", " + advisor + ", " + address + ", " + credit + ", " + major + ", " + company + ", " + department + ", " + position);
	}
	
	public String getShowOfStringData()
	{
		return id + ", " + type + ", " + name + ", " + Integer.toString(grade) + ", " + advisor + ", " + address + ", " + Double.toString(credit) + ", " + major + ", " + company + ", " + department + ", " + position;
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
