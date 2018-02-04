package 은행관리;

public class Bank
{
	private static final int BALANCE_INQUIRY = 1;
	private static final int WITHDRAWL = 2;
	private static final int DEPOSIT = 3;
	private static final int MENU_RETURN = 4;
	private static final int WORKMENU_EXIT = 5;
	
	private static final int CREATE_ACCOUNT = 1;
	private static final int DISPLAY_ACCOUNT = 2;
	private static final int DELETE_ACCOUNT = 3;
	private static final int OPERATION_ACCOUNT = 4;
	private static final int MAINMENU_EXIT = 5;
	
	
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
		performAccountTransactions();
	}
	
	private void authenticateUser() // 사용자 인증
	{
		screen.displayMessage("\n계좌번호 입력: ");
		int account_number = keypad.getInteger();
		screen.displayMessage("\nPIN 입력: ");
		int pin = keypad.getInteger();
		
		user_authenticated = bank_database.authenticateUser(account_number, pin);
		if(user_authenticated)
		{
			current_accountnumber = account_number;
		}
		else
		{
			screen.displayMsgLine("유효하지 않는 계좌번호 or PIN. 종료합니다.");
		}
	}
	
	private void performWorkTransactions() // work menu display & transaction perform
	{
		int menu_selection;
		Transaction current_transaction = null;

		LOOP: while(true)
		{
			switch(menu_selection = screen.displayWorkMenu())
			{
			case BALANCE_INQUIRY:	case WITHDRAWL:	case DEPOSIT:
				current_transaction = createWorkTransaction(menu_selection);
				current_transaction.execute();
				break;
			case MENU_RETURN:
				screen.displayMsgLine("\nMain Menu로 돌아가기");
				performAccountTransactions();
				break;
			case WORKMENU_EXIT:
				screen.displayMsgLine("\n프로그램을 종료합니다.");
				break LOOP;
			default:
				screen.displayMsgLine("\n선택 오류.");
				break;
			}
		}
	}
	
	private void performAccountTransactions() // main menu display & transaction perform
	{
		int menu_selection;
		Transaction current_transaction = null;
		
		while(true)
		{
			switch(menu_selection = screen.displayMainMenu())
			{
			case CREATE_ACCOUNT:	case DISPLAY_ACCOUNT:	case DELETE_ACCOUNT:
				current_transaction = createAccountTransaction(menu_selection);
				current_transaction.execute();
				break;
			case OPERATION_ACCOUNT:
				authenticateUser();
				if(user_authenticated)
				{
					performWorkTransactions();
				}
			case MAINMENU_EXIT:
				screen.displayMsgLine("\n프로그램을 종료합니다.");
				System.exit(1);
			default:
				screen.displayMsgLine("\n선택 오류.");
				break;
			}
		}
	}
	
	private Transaction createWorkTransaction(int type) // create transaction & return transaction
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
			temp = new Deposit(current_accountnumber, screen, bank_database, keypad);
			break;
		}
		return temp;
	}
	
	private Transaction createAccountTransaction(int type) // create transaction & return transaction
	{
		Transaction temp = null;
		
		switch(type)
		{
		case CREATE_ACCOUNT:
			temp = new CreateAccount(current_accountnumber, screen, bank_database, keypad);
			break;
		case DISPLAY_ACCOUNT:
			temp = new DisplayAccount(current_accountnumber, screen, bank_database);
			break;
		case DELETE_ACCOUNT:
			temp = new DeleteAccount(current_accountnumber, screen, bank_database, keypad);
			break;
		}
		return temp;
	}
}