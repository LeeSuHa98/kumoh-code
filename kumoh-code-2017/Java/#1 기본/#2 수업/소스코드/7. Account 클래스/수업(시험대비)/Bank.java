package 수업;

public class Bank
{
	private final int MAX_SIZE = 100;
	
	private Account[] account_list = new Account[MAX_SIZE]; // 객체배열 할당
	private int count;
	
	public Bank()
	{
		count = 0;
	}
	
	public Account findAccount(int account_number)//계좌검색
	{
		int index = 0;
		for(int i = 0; i < count; i++)
		{
			int temp = account_list[i].getAccountNumber();
			if(temp == account_number)
			{
				return account_list[index];
			}
			else if(temp != account_number)
			{
				index++;
			}
		}
		return null;
	}
	
	public void createAccount(String owner, long balance)
	{
		account_list[count] = new Account(owner, balance);
		count++;
		System.out.println("계좌 생성 완료!");
	}
	
	public long sumAccount()
	{
		long sum = 0;
		for(int i = 0; i < count; i++)
		{
			sum += account_list[i].getBalance();
		}
		return sum;
	}
	
	public void showBank()
	{
		for(int i = 0; i < count; i++)
		{
			System.out.println("각 계좌의 상태 출력");
			account_list[i].showAccount();
			System.out.println("계좌 개수 : " + count);
			System.out.println("예금 총액 : " + sumAccount());
		}
	}
}
