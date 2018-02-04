public class Account 
{
	private int account_num;
	private long balance;
	private Owner owner;
	
	public Account()
	{
		account_num = 0;
		balance = 0;
	}
	public Account(long money, Owner owner)
	{
		balance = money;
		this.owner = owner;
	}

	public int getAccountNum()
	{
		return account_num;
	}
	public long getBalance()
	{
		return balance;
	}
	public void setAccountNum(int account_num)
	{
		this.account_num = account_num;
	}
	public void setOwner(Owner owner)
	{
		this.owner = owner;
	}
}