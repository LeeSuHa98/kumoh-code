package 명단관리;

public class Faculty extends Member
{
	private int major; //전공분야
	private String degree; //최종학위
	
	public Faculty(String id, String name, String department,int major, String degree)
	{
		super(id, name, department);
		// TODO Auto-generated constructor stub
		this.major = major;
		this.degree = degree;
	}

	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("성명 : " + name);
		System.out.println("소속학과 : " + department);
		System.out.println("전공분야 : " + major);
		System.out.println("최종학위 : " + degree);
	}
}
