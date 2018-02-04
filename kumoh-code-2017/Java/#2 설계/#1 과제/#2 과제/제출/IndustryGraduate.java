package 명단관리;

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
		System.out.println("과정 : " + this.curriculum);
		System.out.println("성명 : " + this.name);
		System.out.println("학년 : " + this.grade);
		System.out.println("지도교수 : " + this.advisor);
		System.out.println("주소 : " + this.address);
		System.out.println("연구분야 : " + this.major);
		System.out.println("회사 : " + company);
		System.out.println("부서 : " + department);
		System.out.println("직책 : " + position);
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
