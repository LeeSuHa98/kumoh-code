public class Account
{
	private int account_number;
	private int pin;
	private int balance;
	
	public Account(int account_number, int pin, int amount)
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
	public int getBalance(){return balance;}
	public void credit(int amount){this.balance += amount;} // �Ա�
	public void debit(int amount){this.balance -= amount;} // ���
}
