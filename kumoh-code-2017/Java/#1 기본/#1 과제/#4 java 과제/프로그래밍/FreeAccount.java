import java.io.Serializable;

public class FreeAccount extends Account implements Serializable
{
	private long money;
	
	public FreeAccount()
	{
		money = 0;
	}
	
	public FreeAccount(long balance)
	{
		super(balance);
	}
	
	public void deposit(long balance)
	{
		money = (long)(this.getBalance() + (balance * 1.02));
		
		plusBalance(money);
	}
	
	public void withdraw(long balance)
	{
		money = (long)(this.getBalance() - (balance * 1.02));
		
		minusBalance(money);
	}
}
