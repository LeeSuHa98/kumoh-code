package 은행관리;

import java.util.ArrayList;

public class BankDatabase
{
	private ArrayList<Account>account_list;
	
	public BankDatabase()
	{
		account_list = new ArrayList<Account>();
	}
	
	private Account findAccount(int account_number) // 할당된 은행 리스트 중 계좌번호를 검색
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
	
	public boolean checkAccount(int account_number) // 할당된 은행 리스트 중 계좌번호를 검색
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

	public void insertAccount(Account acc) // 계좌정보 삽입
	{
		account_list.add(acc);
	}
	
	public void deleteAccount(int account_number) // 계좌정보 삭제
	{
		for(int i = 0; i < account_list.size(); i++)
		{
			if(account_number == account_list.get(i).getAccountNumber())
			{
				account_list.remove(i);
			}
		}
	}
	
	public void displayAccount() // 계좌정보 출력
	{
		for(int i = 0; i < account_list.size(); i++)
		{
			System.out.println("계좌번호: " + account_list.get(i).getAccountNumber());
			System.out.println("잔고: " + account_list.get(i).getBalance());
		}
	}
	
	public boolean authenticateUser(int account_number, int pin) // 일치하는 계좌번호의 암호검색
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
