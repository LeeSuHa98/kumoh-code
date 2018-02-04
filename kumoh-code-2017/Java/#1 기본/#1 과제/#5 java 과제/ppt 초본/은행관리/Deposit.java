public class Deposit extends Transaction
{
	private final static int CANCELED = 0;
	private int amount;
	private Keypad keypad;
	
	public Deposit(int account_number, Screen screen, BankDatabase bank_database)
	{
		super(account_number, screen, bank_database);
		this.keypad = keypad;
	}
	
	private int depositAmount()
	{
		Screen screen = getScreen();
		screen.displayMessage("\n�Աݾ��� �Է��Ͻÿ� (����Ϸ��� 0): ");
		int input = keypad.getInteger();
		return (input == CANCELED) ? CANCELED : input;
	}
	
	public void execute()
	{
		BankDatabase bank_database = getBankDatabase();
		Screen screen = getScreen();
		amount = depositAmount();
		if(amount != CANCELED)
		{
			bank_database.credit(getAccountNumber(), amount);
			screen.displayMsgLine("\n�Ա��� �Ϸ�Ǿ����ϴ�.");
		}
		else
		{
			screen.displayMsgLine("\n�Ա��� ����մϴ�.");
		}
	}
}

