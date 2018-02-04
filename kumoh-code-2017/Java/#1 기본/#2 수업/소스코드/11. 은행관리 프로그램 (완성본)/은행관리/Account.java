package 은행관리;

public class Account
{
	private int account_number;
	private int pin;
	private long balance;
	
	public Account(){}
	public Account(int account_number, int pin, long amount)
	{
		this.account_number = account_number;
		this.pin = pin;
		this.balance = amount;
	}
	
	public boolean validatePIN(int pin) // 암호검사
	{
		return (this.pin == pin) ? true : false;
	}
	
	public int getAccountNumber(){return account_number;}
	public long getBalance(){return balance;}
	public void credit(long amount){this.balance += amount;} // 입금
	public void debit(long amount){this.balance -= amount;}; // 출금
	
	protected void plusBalance(long balance){this.balance += balance;}
	protected void minusBalance(long balance){this.balance -= balance;}
}
