public class Account {

	int accountnum;;
	long balance;
	Owner owner;
	
	Account()
	{
	}
	Account(long money, Owner owner)
	{
		balance = money;
		this.owner=owner;
	}
	int getAccountnum()
	{
		return accountnum;
	}
	long getBalance()
	{
		return balance;
	}
	void setAccountnum(int accountnum)
	{
		this.accountnum=accountnum;
	}
	void setOwner(Owner owner)
	{
		this.owner=owner;
	}
}
