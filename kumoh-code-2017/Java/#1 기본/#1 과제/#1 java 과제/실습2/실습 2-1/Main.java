import java.util.Scanner;

public class Main
{	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		StudentList s_list = new StudentList();
		
		while(true)
		{	
			System.out.println("------ �л����� ���α׷� ------");
			System.out.println("------ 1. �л����� ��� ------");
			System.out.println("------ 2. �л����� ��� ------");
			System.out.println("------ 3. ���α׷� ���� ------");
			System.out.print("���� : ");
			
			int select;
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				s_list.registerStudent();
				break;
			case 2:
				s_list.displayStudent();
				break;
			case 3:
				System.exit(1);
			}
		}
	}
}
