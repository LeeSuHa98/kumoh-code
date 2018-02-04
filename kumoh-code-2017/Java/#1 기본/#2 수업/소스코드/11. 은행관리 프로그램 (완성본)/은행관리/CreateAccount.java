package 은행관리;

public class CreateAccount extends Transaction
{
	private Keypad keypad;
	
	public CreateAccount(int account_number, Screen screen, BankDatabase bank_database, Keypad keypad)
	{
		super(account_number, screen, bank_database);
		
		this.keypad = keypad;
	}
	
	public void execute()
	{
		boolean check = true;
		Screen screen = getScreen();
		BankDatabase bank_database = getBankDatabase();
		while(check != false)
		{
			screen.displayMessage("\n계좌번호 입력: ");
			int account_number = keypad.getInteger();
			boolean check_account = bank_database.checkAccount(account_number);
			if(check_account)
			{
				screen.displayMessage("\nPIN 입력: ");
				int pin = keypad.getInteger();
				screen.displayMessage("\n예금액 입력: ");
				long balance = keypad.getLong();
				
				int menu = screen.displayAccountMenu();
				switch(menu)
				{
				case 1:
					Account acc = new Account(account_number, pin, balance);
					bank_database.insertAccount(acc);
					
					check = false;
					check_account = false;
					break;
				case 2:
					FreeAccount f_acc = new FreeAccount(account_number, pin, balance);
					bank_database.insertAccount(f_acc);
					
					check = false;
					check_account = false;
					break;
				case 3:
					MinusAccount m_acc = new MinusAccount(account_number, pin, balance);
					bank_database.insertAccount(m_acc);
					
					check = false;
					check_account = false;
					break;
				default:
					screen.displayMessage("잘못된 번호를 입력하였습니다.");
					break;
				}
			}
			else
			{
				screen.displayMsgLine("중복된 계좌를 입력하였습니다.");
			}
		}
	}
}
