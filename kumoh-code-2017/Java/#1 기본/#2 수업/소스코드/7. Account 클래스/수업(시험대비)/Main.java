package 수업;

import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		Account a = new Account();
		Bank b = new Bank();

		int account_number;
		String owner;
		long balance;
		
		while(true)
		{
			System.out.println("------Account Program------");
			System.out.println("------1. 계좌 개설          ------");
			System.out.println("------2. 입금                ------");
			System.out.println("------3. 출금                ------");
			System.out.println("------4. 계좌 조회          ------");
			System.out.println("------5. 프로그램 종료     ------");
			
			int select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				System.out.print("예금주 : ");
				owner = sc.next();
				System.out.print("잔고 : ");
				balance = sc.nextLong();
				b.createAccount(owner, balance);
				break;
			case 2:
				System.out.print("입금할 계좌번호 : ");
				account_number = sc.nextInt();
				a = b.findAccount(account_number);
				System.out.print("입금 : ");
				balance = sc.nextLong();
				a.deposit(balance);
				break;
			case 3:
				System.out.print("출금할 계좌번호 : ");
				account_number = sc.nextInt();
				a = b.findAccount(account_number);
				System.out.print("출금 : ");
				balance = sc.nextLong();
				a.withdraw(balance);
				break;
			case 4:
				System.out.println("계좌조회 : ");
				b.showBank();
				break;
			case 5:
				System.exit(1);
			}
		}
	}
}
