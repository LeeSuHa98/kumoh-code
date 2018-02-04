﻿package 과제;

public class Account
{
	private String account_number; // 계좌번호
	private String Owner; // 예금주
	private long balance; // 잔고
	
	public Account(String account_number, String Owner, long balance)
	{
		this.account_number = account_number;
		this.Owner = Owner;
		this.balance = balance;
	}
	
	public String getAccountNumber(){return account_number;}
	public String getOwner(){return Owner;}
	public long getBalance(){return balance;}
	
	public void deposit(long balance)
	{
		this.balance += balance;
	}
	public long withdraw(long balance)
	{
		if(this.balance >= balance)
		{
			return this.balance -= balance;
		}
		else
		{
			return balance;
		}
	}
}
