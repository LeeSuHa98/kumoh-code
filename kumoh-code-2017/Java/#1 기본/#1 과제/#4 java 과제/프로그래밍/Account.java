public abstract class Account implements IAccount
{
	private static int last_acc_num = 0;
	private int acc_num;
	private long balance;
	
	public Account()
	{
		balance = 0;
	}
	
	public Account(long balance)
	{
		acc_num = nextAccNum();
		this.balance = balance;
	}
	
	public int getAccNum(){return acc_num;}
	public long getBalance(){return balance;}
	public abstract void deposit(long balance);
	public abstract void withdraw(long balance);
	
	protected void plusBalance(long balance){this.balance += balance;}
	protected void minusBalance(long balance){this.balance -= balance;}
	protected static int nextAccNum(){return ++last_acc_num;}
	
	public void showAccount()
	{
		System.out.println("AccountNumber : " + getAccNum());
		System.out.println("AccountBalance : " + getBalance());
	}
}