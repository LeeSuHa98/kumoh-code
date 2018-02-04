import java.util.Scanner;

public class Main
{	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		StudentList s_list = new StudentList();
		
		while(true)
		{	
			System.out.println("------ 학생정보 프로그램 ------");
			System.out.println("------ 1. 학생정보 등록 ------");
			System.out.println("------ 2. 학생정보 출력 ------");
			System.out.println("------ 3. 프로그램 종료 ------");
			System.out.print("선택 : ");
			
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
