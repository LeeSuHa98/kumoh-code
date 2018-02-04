public class Account
{
	private String account_number; // ���¹�ȣ
	private String account_holder; // ������
	private long balance; // �ܰ�
	
	public Account(String account_number, String account_holder, long balance)
	{
		this.account_number = account_number;
		this.account_holder = account_holder;
		this.balance = balance;
	}
	
	public String getAccountHolder(){return account_holder;}
	public String getAccountNumber(){return account_number;}
	public long getBalance(){return balance;}
	public void setBalance(long balance){this.balance = balance;}
}
