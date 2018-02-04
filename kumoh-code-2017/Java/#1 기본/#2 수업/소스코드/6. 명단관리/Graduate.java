package 명단관리;

public class Graduate extends Student
{
	private String degree; //학위과정
	private int major; //전공분야
	
	public Graduate(String id, String name, String department, String degree, int major, String advisor)
	{
		super(id, name, department, advisor);
		// TODO Auto-generated constructor stub
		this.degree = degree;
		this.major = major;
	}
	
	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("성명 : " + name);
		System.out.println("소속학과 : " + department);
		System.out.println("학위과정 : " + degree);
		System.out.println("전공분야 : " + major);
		System.out.println("지도교수 : " + advisor);
	}
}
