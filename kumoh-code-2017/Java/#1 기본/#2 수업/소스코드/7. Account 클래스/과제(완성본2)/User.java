package 과제;

import java.util.Scanner;

public class User
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		Manager a_list = new Manager();
		
		while(true)
		{
			System.out.println("------ Account 프로그램 ------");
			System.out.println("------ 1. 계좌개설          ------");
			System.out.println("------ 2. 잔고조회          ------");
			System.out.println("------ 3. 입금               ------");
			System.out.println("------ 4. 출금               ------");
			System.out.println("------ 5. 프로그램 종료    ------");
			System.out.print("선택 : ");
			
			int select;
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				//계좌개설
				a_list.creatAccount();
				break;
			case 2:
				//잔고조회
				a_list.showAccount();
				break;
			case 3:
				//입금
				a_list.depositAccount();
				break;
			case 4:
				//출금
				a_list.withdrawAccount();
				break;
			case 5:
				//프로그램 종료
				System.exit(1);
			}
		}
	}
}

