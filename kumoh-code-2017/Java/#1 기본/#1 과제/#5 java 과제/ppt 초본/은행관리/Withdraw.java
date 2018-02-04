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
		screen.displayMessage("\n출금액을 입력하시오 (취소하려면 0): ");
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
				screen.displayMsgLine("\n출금이 완료되었습니다.");
			}
			else
			{
				screen.displayMsgLine("\n잔고가 부족합니다.");
			}
		}
		return;
	}
}

