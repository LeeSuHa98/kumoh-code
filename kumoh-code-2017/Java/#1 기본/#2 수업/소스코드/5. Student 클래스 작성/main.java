package part1;
import java.util.Scanner;

public class main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		String name;
		int num;
		
		System.out.println("�й�1 �й� : ");
		num = sc.nextInt();
		
		System.out.println("�й�1 �̸� : ");
		name = sc.next();
		
		Student s1 = new Student(name,num);

		System.out.println("�й�2 �й� : ");
		num = sc.nextInt();
		
		System.out.println("�й�2 �̸� : ");
		name = sc.next();
		
		Student s2 = new Student(name,num);

		s1.printInfo();
		s2.printInfo();

		ComparisonSnum cs = new ComparisonSnum();
		cs.compareSnum(s1,s2);
	}
}
