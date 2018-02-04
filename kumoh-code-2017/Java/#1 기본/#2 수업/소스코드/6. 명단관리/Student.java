package 명단관리;

public class Student extends Member
{
	protected String advisor; //지도교수
	public Student(String id, String name, String department, String advisor)
	{
		super(id, name, department);
		// TODO Auto-generated constructor stub
		this.advisor = advisor;
	}
	
	public void putMember(){}
}
