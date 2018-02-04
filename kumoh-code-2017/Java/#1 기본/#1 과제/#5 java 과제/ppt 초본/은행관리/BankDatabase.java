public class BankDatabase
{
	private Account[] accounts;
	public BankDatabase()
	{
		accounts = new Account[3];
		accounts[0] = new Account(1, 1201, 1000);
		accounts[1] = new Account(2, 1202, 2000);
		accounts[2] = new Account(3, 1203, 3000);
	}
	
	private Account findAccount(int account_number) // �Ҵ�� ���� ����Ʈ �� ���¹�ȣ�� �˻�
	{
		for(Account acc : accounts)
		{
			if(acc.getAccountNumber() == account_number)
			{
				return acc;
			}
		}
		
		return null;
	}
	
	public boolean authenticateUser(int account_number, int pin) // ��ġ�ϴ� ���¹�ȣ�� ��ȣ�˻�
	{
		Account acc = findAccount(account_number);
		return (acc != null) ? acc.validatePIN(pin) : false;
	}
	
	public int getBalance(int account_number)
	{
		return findAccount(account_number).getBalance();
	}
	
	public void credit(int account_number, int amount)
	{
		findAccount(account_number).credit(amount);
	}
	
	public void debit(int account_number, int amount)
	{
		findAccount(account_number).debit(amount);
	}
}
