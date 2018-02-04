public class Account implements Cloneable
{
	private String name;
	private double balance;
	private Account a;

	public Account(String name, double balance)
	{
		this.name = name;
		this.balance = balance;
	}
	public Account() 
	{
		name = "000";
		balance = 0;
	}

	public String getName()
	{
		return name;
	}
	public double getBalance()
	{
		return balance;
	}
 	public void setName(String name)
 	{
 		this.name = name;
 	}
 	public void setBalance(double balance)
 	{
 		this.balance = balance;
 	}
 	public void printAccount()
 	{
 		System.out.println("Owner : " + name);
 		System.out.println("Balance : " + balance);
 	}
 	protected Object clone()
 	{
 		try 
 		{
 	   		Account s = (Account)super.clone();
 	   		return s;				
 		} 
 		catch (CloneNotSupportedException e)
 		{
 			  e.printStackTrace();
 	          return null;	
 	    }
 	}	
}