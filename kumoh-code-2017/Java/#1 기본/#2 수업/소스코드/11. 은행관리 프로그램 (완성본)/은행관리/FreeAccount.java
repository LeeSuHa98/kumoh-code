package 은행관리;

public class FreeAccount extends Account
{
	private long money;
	
	public FreeAccount(int account_number, int pin, long amount)
	{
		super(account_number, pin, amount);
	}
    
	public void credit(long amount)
	{
		money = (long)(this.getBalance() + (amount * 1.02));
		
		plusBalance(money);
	}
	
    public void debit(long amount) 
    {
		money = (long)(this.getBalance() - (amount * 1.02));
		
		minusBalance(money);
    }
}
