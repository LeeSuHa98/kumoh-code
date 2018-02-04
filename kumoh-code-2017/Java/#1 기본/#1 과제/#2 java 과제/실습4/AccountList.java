import java.util.Scanner;

public class AccountList
{
	Scanner sc = new Scanner(System.in);
	
	final int MAX_ACCOUNT = 10;
	
	private Account[] account_list = new Account[MAX_ACCOUNT];
	private int count;
	
	public AccountList()
	{
		count = 0;
	}
	
	public Account findAccount(String account_number)//���°˻�
	{
		int index = 0;
		for(int i = 0; i < count; i++)
		{
			String temp = account_list[i].getAccountNumber();
			if(temp.equals(account_number))
			{
				return account_list[index];
			}
			else if(!temp.equals(account_number))
			{
				index++;
			}
		}
		return null;
	}
	public void creatAccount() // ���°���
	{
		System.out.println("���¸� �����մϴ�.");
		
		System.out.print("���¹�ȣ : ");
		String account_number = sc.next();
		
		System.out.print("������ : ");
		String account_holder = sc.next();
		
		System.out.print("���ݾ� : ");
		long deposit = sc.nextLong();
		
		Account a = new Account(account_number, account_holder, deposit);
		account_list[count] = a;
		count++;
	}
	public void showAccount() // �ܰ���ȸ
	{
		System.out.println("������ �ܰ� ��ȸ�մϴ�.");
		
		for(int i = 0; i < count; i++)
		{
			System.out.println("���¹�ȣ : " + account_list[i].getAccountNumber());
			System.out.println("������ : " + account_list[i].getAccountHolder());
			System.out.println("�ܰ� : " + account_list[i].getBalance());
		}
	}
	public void depositAccount() // �Ա�
	{
		System.out.println("���¿� �ݾ��� �Ա��մϴ�.");
		System.out.print("���¹�ȣ  : ");
		String account_number = sc.next();
		
		if(findAccount(account_number) == null)
		{
			System.out.println("�������� �ʴ� ���¹�ȣ�Դϴ�.");
		}
		else
		{
			Account a = findAccount(account_number);
			
			System.out.println("�󸶸� �Ա��Ͻðڽ��ϱ�?");
			System.out.print("�Աݾ� : ");
			long balance = sc.nextLong();
			a.setBalance(a.getBalance() + balance);
		}
	}
	public void withdrawAccount() // ���
	{
		System.out.println("������ �ݾ��� ����մϴ�.");
		System.out.print("���¹�ȣ  : ");
		String account_number = sc.next();
		if(findAccount(account_number) == null)
		{
			System.out.println("�������� �ʴ� ���¹�ȣ�Դϴ�.");
		}
		else
		{
			Account a = findAccount(account_number);
			
			System.out.println("�󸶸� ����Ͻðڽ��ϱ�?");
			System.out.print("��ݾ� : ");
			long balance = sc.nextLong();
			a.setBalance(a.getBalance() - balance);
		}
	}
}
