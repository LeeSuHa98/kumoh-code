import java.util.Scanner;

public class StudentList
{
	Scanner sc = new Scanner(System.in);
	
	final int MAX_STUDENT = 100;
	
	private Student[] student_list = new Student[MAX_STUDENT];
	private int count;
	
	public void registerStudent()
	{
		System.out.println("학생 정보를 등록합니다.");
		
		System.out.print("학과 : ");
		String major = sc.next(); // 학과
		
		System.out.print("학년 : ");
		int grade = sc.nextInt(); // 학년
		
		System.out.print("학번 : ");
		int id = sc.nextInt(); // 학번
		
		System.out.print("이름 : ");
		String name = sc.next(); // 이름
		
		System.out.print("성별 : ");
		String sex = sc.next(); // 성별
		
		System.out.print("생일 : ");
		String birth = sc.next(); // 생일
		
		System.out.print("체중 : ");
		float weight = (float)sc.nextInt(); // 체중
		
		System.out.print("주소 : ");
		String address = sc.next(); // 주소
		
		Student s = new Student(major, grade, id, name, sex, birth, weight, address);
		
		student_list[count] = s;
		count++;
		
		System.out.println();
	}
	
	public void displayStudent()
	{
		System.out.println("학생 정보를 출력합니다.");
		
		for(int i = 0; i < count; i++)
		{
			System.out.println("학과 : " + student_list[i].getMajor());
			System.out.println("학년 : " + student_list[i].getGrade());
			System.out.println("학번 : " + student_list[i].getId());
			System.out.println("이름 : " + student_list[i].getName());
			System.out.println("성별 : " + student_list[i].getSex());
			System.out.println("생일 : " + student_list[i].getBirth());
			System.out.println("체중 : " + student_list[i].getWeight());
			System.out.println("주소 : " + student_list[i].getAddress());
			System.out.println();
		}
	}
}
