public class Withdraw extends Transaction
{
	private final static int CANCELED = 0;
	private int amount;
	private Keypad keypad;
	
	public Withdraw(int account_number, Screen screen, BankDatabase bank_database, Keypad keypad)
	{
		super(account_number, screen, bank_database);
		this.keypad = keypad;
	}
	
	private int withdrawAmount()
	{
		Screen screen = getScreen();
		screen.displayMessage("\n��ݾ��� �Է��Ͻÿ� (����Ϸ��� 0): ");
		int input = keypad.getInteger();
		return (input == CANCELED) ? CANCELED : input;
	}
	
	public void execute()
	{
		int balance;
		BankDatabase bank_database = getBankDatabase();
		Screen screen = getScreen();
		
		amount = withdrawAmount();
		if(amount != CANCELED)
		{
			balance = bank_database.getBalance(getAccountNumber());
			if(amount <= balance)
			{
				bank_database.debit(getAccountNumber(), amount);
				screen.displayMsgLine("\n����� �Ϸ�Ǿ����ϴ�.");
			}
			else
			{
				screen.displayMsgLine("\n�ܰ� �����մϴ�.");
			}
		}
		return;
	}
}

