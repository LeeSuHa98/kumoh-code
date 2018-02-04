package �������;

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
	
	public boolean validatePIN(int pin) // ��ȣ�˻�
	{
		return (this.pin == pin) ? true : false;
	}
	
	public int getAccountNumber(){return account_number;}
	public long getBalance(){return balance;}
	public void credit(long amount){this.balance += amount;} // �Ա�
	public void debit(long amount){this.balance -= amount;}; // ���
	
	protected void plusBalance(long balance){this.balance += balance;}
	protected void minusBalance(long balance){this.balance -= balance;}
}
