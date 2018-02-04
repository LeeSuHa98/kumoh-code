public class Bank
{
	private static final int BALANCE_INQUIRY = 1;
	private static final int WITHDRAWL = 2;
	private static final int DEPOSIT = 3;
	private static final int EXIT = 4;
	
	private boolean user_authenticated;
	private int current_accountnumber;	// Model's Business Object
	private BankDatabase bank_database;	// Model's Business Object
	private Screen screen; // UI Component
	private Keypad keypad; // UI Component
	
	public Bank()	// constants corresponding to main menu options
	{
		user_authenticated = false;
		current_accountnumber = 0;
		bank_database = new BankDatabase();
		screen = new Screen();
		keypad = new Keypad();
	}
	
	public void run() // start Bank
	{
		authenticateUser();
		if(user_authenticated)
		{
			performTransactions();
		}
	}
	
	private void authenticateUser() // ����� ����
	{
		screen.displayMessage("\n���¹�ȣ �Է�: ");
		int account_number = keypad.getInteger();
		screen.displayMessage("\nPIN �Է�:");
		int pin = keypad.getInteger();
		
		user_authenticated = bank_database.authenticateUser(account_number, pin);
		if(user_authenticated)
		{
			current_accountnumber = account_number;
		}
		else
		{
			screen.displayMsgLine("��ȿ���� �ʴ� ���¹�ȣ or PIN. �����մϴ�.");
		}
	}
	
	private void performTransactions() // main menu display & transaction perform
	{
		int menu_selection;
		Transaction current_transaction = null;

		LOOP: while(true)
		{
			switch(menu_selection = getMenu())
			{
			case BALANCE_INQUIRY:	case WITHDRAWL:	case DEPOSIT:
				current_transaction = createTransaction(menu_selection);
				current_transaction.execute();
				break;
			case EXIT:
				screen.displayMsgLine("\n���α׷��� �����մϴ�.");
				break LOOP;
			default:
				screen.displayMsgLine("\n���� ����.");
				break;
			}
		}
	}
	
	private int getMenu() // main menu display & return select to user
	{
		screen.displayMsgLine("\nMain menu:");
		screen.displayMsgLine("1 - View my balance");
		screen.displayMsgLine("2 - Withdraw cash");
		screen.displayMsgLine("3 - Deposit funds");
		screen.displayMsgLine("4 - Exit\n");
		screen.displayMessage("Enter a choice: ");
		
		return keypad.getInteger();
	}
	
	private Transaction createTransaction(int type) // create transaction & return transaction
	{
		Transaction temp = null;
		
		switch(type)
		{
		case BALANCE_INQUIRY:
			temp = new BalanceInquiry(current_accountnumber, screen, bank_database);
			break;
		case WITHDRAWL:
			temp = new Withdraw(current_accountnumber, screen, bank_database, keypad);
			break;
		case DEPOSIT:
			temp = new Deposit(current_accountnumber, screen, bank_database);
			break;
		}
		return temp;
	}
}