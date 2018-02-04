package 은행관리;

abstract public class Transaction
{
	private int account_number; // Model's Account
	private Screen screen; // UI Component
	private BankDatabase bank_database; // UI Component
	
	public Transaction(int account_number, Screen screen, BankDatabase bank_database)
	{
		this.account_number = account_number;
		this.screen = screen;
		this.bank_database = bank_database;
	}
	
	public int getAccountNumber(){return account_number;}
	public Screen getScreen(){return screen;}
	public BankDatabase getBankDatabase(){return bank_database;}
	
	abstract public void execute(); // Transaction 실행
}
