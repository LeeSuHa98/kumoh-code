package 명단관리;

public class Undergraduate extends Student
{
	private int grade; //학년
	public Undergraduate(String id, String name, String department, int grade, String advisor)
	{
		super(id, name, department, advisor);
		// TODO Auto-generated constructor stub
		this.grade = grade;
	}
	
	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("성명 : " + name);
		System.out.println("소속학과 : " + department);
		System.out.println("학년 : " + grade);
		System.out.println("지도교수 : " + advisor);
	}
}
