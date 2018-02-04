package 은행관리;

public class MinusAccount extends Account
{
	private long money;	
	
	public MinusAccount(int account_number, int pin, long amount)
	{
		super(account_number, pin, amount);
	}
	
	public void credit(long amount)
	{
		money = this.getBalance() + amount;
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
	
	public void debit(long amount)
	{
		money = this.getBalance() - amount;
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
