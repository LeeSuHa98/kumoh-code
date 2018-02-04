package 수업;

public class Account
{
	private static int last_account_number = 0;
	private int account_number; // 계좌번호
	private String owner; // 예금주
	private long balance; // 잔고
	
	public Account(){}
	public Account(String owner, long balance)
	{
		this.account_number = ++last_account_number;
		this.owner = owner;
		this.balance = balance;
	}
	
	public int getAccountNumber(){return account_number;}
	public String getOwner(){return owner;}
	public long getBalance(){return balance;}
	
	public void deposit(long balance) // 입금
	{
		this.balance += balance;
	}
	public long withdraw(long balance) // 출금
	{
		if(this.balance >= balance)
		{
			return this.balance -= balance;
		}
		else
		{
			return balance;
		}
	}
	public void showAccount() // 계좌상태 출력
	{
		System.out.println("계좌번호 : " + account_number);
		System.out.println("예금주 : " + owner);
		System.out.println("잔고 : " + balance);
	}
}
