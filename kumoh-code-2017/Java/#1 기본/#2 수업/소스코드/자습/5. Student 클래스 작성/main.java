package part1;
import java.util.Scanner;

public class main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		String name;
		int num;
		
		System.out.println("학번1 학번 : ");
		num = sc.nextInt();
		
		System.out.println("학번1 이름 : ");
		name = sc.next();
		
		Student s1 = new Student(name,num);

		System.out.println("학번2 학번 : ");
		num = sc.nextInt();
		
		System.out.println("학번2 이름 : ");
		name = sc.next();
		
		Student s2 = new Student(name,num);

		s1.printInfo();
		s2.printInfo();

		ComparisonSnum cs = new ComparisonSnum();
		cs.compareSnum(s1,s2);
	}
}
