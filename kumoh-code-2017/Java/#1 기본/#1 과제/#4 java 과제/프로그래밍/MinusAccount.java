import java.io.Serializable;

public class MinusAccount extends Account implements Serializable
{
	private long money;
	
	public MinusAccount()
	{
		money = 0;
	}
	
	public MinusAccount(long balance)
	{
		super(balance);
	}
	
	public void deposit(long balance)
	{
		money = this.getBalance() + balance;
		if(money > 0)
		{
			money = (long)(money * 1.01);
			plusBalance(money);
		}
		else
		{
			money = (long)(money * 1.05);
			plusBalance(money);
		}
	}
	
	public void withdraw(long balance)
	{
		money = this.getBalance() - balance;
		if(money > 0)
		{
			money = (long)(money * 1.01);
			minusBalance(money);
		}
		else
		{
			money = (long)(money * 1.05);
			minusBalance(money);
		}
	}
}