package 은행관리;

public class BalanceInquiry extends Transaction
{
	public BalanceInquiry(int account_number, Screen screen, BankDatabase bank_database)
	{
		super(account_number, screen, bank_database);
	}
	
	public void execute()
	{
		BankDatabase bank_database = getBankDatabase();
		Screen screen = getScreen();
		
		int balance = bank_database.getBalance(getAccountNumber());
		
		screen.displayMessage("잔고 : ");
		screen.displayAmount(balance);
		screen.displayMsgLine("");
	}
}
