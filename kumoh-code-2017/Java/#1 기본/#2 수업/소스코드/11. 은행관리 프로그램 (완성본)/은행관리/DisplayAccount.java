package �������;

public class DisplayAccount extends Transaction
{
	public DisplayAccount(int account_number, Screen screen, BankDatabase bank_database)
	{
		super(account_number, screen, bank_database);
	}
	
	public void execute()
	{
		Screen screen = getScreen();
		BankDatabase bank_database = getBankDatabase();
		screen.displayMsgLine("\n���³����� ��ȸ�մϴ�.");
		bank_database.displayAccount();
	}
}
