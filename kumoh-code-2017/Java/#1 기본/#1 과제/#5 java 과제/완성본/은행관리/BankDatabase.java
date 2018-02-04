package �������;

import java.util.ArrayList;

public class BankDatabase
{
	private ArrayList<Account>account_list;
	
	public BankDatabase()
	{
		account_list = new ArrayList<Account>();
	}
	
	private Account findAccount(int account_number) // �Ҵ�� ���� ����Ʈ �� ���¹�ȣ�� �˻�
	{

		for(int i = 0; i < account_list.size(); i++)
		{
			if(account_list.get(i).getAccountNumber() == account_number)
			{
				return account_list.get(i);
			}
		}
		
		return null;
	}
	
	public boolean checkAccount(int account_number) // �Ҵ�� ���� ����Ʈ �� ���¹�ȣ�� �˻�
	{
		boolean check = true;

		for(int i = 0; i < account_list.size(); i++)
		{
			if(account_list.get(i).getAccountNumber() == account_number)
			{
				check = false;
			}
		}
		return check;
	}

	public void insertAccount(Account acc) // �������� ����
	{
		account_list.add(acc);
	}
	
	public void deleteAccount(int account_number) // �������� ����
	{
		for(int i = 0; i < account_list.size(); i++)
		{
			if(account_number == account_list.get(i).getAccountNumber())
			{
				account_list.remove(i);
			}
		}
	}
	
	public void displayAccount() // �������� ���
	{
		for(int i = 0; i < account_list.size(); i++)
		{
			System.out.println("���¹�ȣ: " + account_list.get(i).getAccountNumber());
			System.out.println("�ܰ�: " + account_list.get(i).getBalance());
		}
	}
	
	public boolean authenticateUser(int account_number, int pin) // ��ġ�ϴ� ���¹�ȣ�� ��ȣ�˻�
	{
		Account acc = findAccount(account_number);
		return (acc != null) ? acc.validatePIN(pin) : false;
	}
	
	public long getBalance(int account_number)
	{
		return findAccount(account_number).getBalance();
	}
	
	public void credit(int account_number, long amount)
	{
		findAccount(account_number).credit(amount);
	}
	
	public void debit(int account_number, long amount)
	{
		findAccount(account_number).debit(amount);
	}
}
