import java.util.Scanner;

public class StudentList
{
	Scanner sc = new Scanner(System.in);
	
	final int MAX_STUDENT = 100;
	
	private Student[] student_list = new Student[MAX_STUDENT];
	private int count;
	
	public void registerStudent()
	{
		System.out.println("�л� ������ ����մϴ�.");
		
		System.out.print("�а� : ");
		String major = sc.next(); // �а�
		
		System.out.print("�г� : ");
		int grade = sc.nextInt(); // �г�
		
		System.out.print("�й� : ");
		int id = sc.nextInt(); // �й�
		
		System.out.print("�̸� : ");
		String name = sc.next(); // �̸�
		
		System.out.print("���� : ");
		String sex = sc.next(); // ����
		
		System.out.print("���� : ");
		String birth = sc.next(); // ����
		
		System.out.print("ü�� : ");
		float weight = (float)sc.nextInt(); // ü��
		
		System.out.print("�ּ� : ");
		String address = sc.next(); // �ּ�
		
		Student s = new Student(major, grade, id, name, sex, birth, weight, address);
		
		student_list[count] = s;
		count++;
		
		System.out.println();
	}
	
	public void displayStudent()
	{
		System.out.println("�л� ������ ����մϴ�.");
		
		for(int i = 0; i < count; i++)
		{
			System.out.println("�а� : " + student_list[i].getMajor());
			System.out.println("�г� : " + student_list[i].getGrade());
			System.out.println("�й� : " + student_list[i].getId());
			System.out.println("�̸� : " + student_list[i].getName());
			System.out.println("���� : " + student_list[i].getSex());
			System.out.println("���� : " + student_list[i].getBirth());
			System.out.println("ü�� : " + student_list[i].getWeight());
			System.out.println("�ּ� : " + student_list[i].getAddress());
			System.out.println();
		}
	}
}
