package 명단관리;

public class Staff extends Member
{
	private int rank; //직급
	private String duty; //담당업무
	
	public Staff(String id, String name, String department, int rank, String duty)
	{
		super(id, name, department);
		// TODO Auto-generated constructor stub
		this.rank = rank;
		this.duty = duty;
	}

	public void putMember()
	{
		System.out.println();
		System.out.println("ID : " + id);
		System.out.println("성명 : " + name);
		System.out.println("소속부서 : " + department);
		System.out.println("직급 : " + rank);
		System.out.println("담당업무 : " + duty);
	}
}
