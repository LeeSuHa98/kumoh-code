import java.util.Scanner;

public class Manager
{
	Scanner sc = new Scanner(System.in);
	
	final int MAX_ACCOUNT = 10;
	
	private Account[] account_list = new Account[MAX_ACCOUNT];
	private int count;
	
	public Manager()
	{
		count = 0;
	}
	
	public Account findAccount(String account_number)//계좌검색
	{
		int index = 0;
		for(int i = 0; i < count; i++)
		{
			String temp = account_list[i].getAccountNumber();
			if(temp.equals(account_number))
			{
				return account_list[index];
			}
			else if(!temp.equals(account_number))
			{
				index++;
			}
		}
		return null;
	}
	public void creatAccount() // 계좌개설
	{
		System.out.println("계좌를 개설합니다.");
		
		System.out.print("계좌번호 : ");
		String account_number = sc.next();
		
		System.out.print("예금주 : ");
		String account_holder = sc.next();
		
		System.out.print("예금액 : ");
		long deposit = sc.nextLong();
		
		Account a = new Account(account_number, account_holder, deposit);
		account_list[count] = a;
		count++;
	}
	public void showAccount() // 잔고조회
	{
		System.out.println("계좌의 잔고를 조회합니다.");
		System.out.print("계좌번호 조회 : ");
		String account_number = sc.next();
		
		
		if(findAccount(account_number) == null)
		{
			System.out.println("존재하지 않는 계좌번호입니다.");
		}
		else
		{
			for(int i = 0; i < count; i++)
			{
				String temp = account_list[i].getAccountNumber();
				if(temp.equals(account_number))
				{
					System.out.println("계좌번호 : " + account_list[i].getAccountNumber());
					System.out.println("예금주 : " + account_list[i].getOwner());
					System.out.println("잔고 : " + account_list[i].getBalance());
				}
			}
		}
	}
	public void depositAccount() // 입금
	{
		System.out.println("계좌에 금액을 입금합니다.");
		System.out.print("계좌번호  : ");
		String account_number = sc.next();
		
		if(findAccount(account_number) == null)
		{
			System.out.println("존재하지 않는 계좌번호입니다.");
		}
		else
		{
			Account a = findAccount(account_number);
			
			System.out.println("얼마를 입금하시겠습니까?");
			System.out.print("입금액 : ");
			long balance = sc.nextLong();
			a.setBalance(a.getBalance() + balance);
		}
	}
	public void withdrawAccount() // 출금
	{
		System.out.println("계좌의 금액을 출금합니다.");
		System.out.print("계좌번호  : ");
		String account_number = sc.next();
		if(findAccount(account_number) == null)
		{
			System.out.println("존재하지 않는 계좌번호입니다.");
		}
		else
		{
			Account a = findAccount(account_number);
			
			System.out.println("얼마를 출금하시겠습니까?");
			System.out.print("출금액 : ");
			long balance = sc.nextLong();
			a.setBalance(a.getBalance() - balance);
		}
	}
}
