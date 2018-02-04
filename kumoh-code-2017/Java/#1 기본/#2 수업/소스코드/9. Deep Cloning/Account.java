package 수업;

public class Account implements Cloneable
{
	private String name;
	private double balance;
	
	public Account()
	{
		name = "000"; 
		balance = 0;
	}
	public Account(String name, double balance)
	{
		this.name = name;
		this.balance = balance;
	}
	public void printAccount()
	{
		System.out.println("Owner : " + name);
		System.out.println("Balance : " + balance);
	}
	
	protected Object clone() throws CloneNotSupportedException
	{
		Account a = (Account)super.clone();
		
		return a;
	}
}
