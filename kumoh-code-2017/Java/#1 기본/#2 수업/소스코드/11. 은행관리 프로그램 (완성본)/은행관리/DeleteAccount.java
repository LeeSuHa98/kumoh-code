package 은행관리;

public class DeleteAccount extends Transaction
{
	private Keypad keypad;

	public DeleteAccount(int account_number, Screen screen, BankDatabase bank_database, Keypad keypad)
	{
		super(account_number, screen, bank_database);
		
		this.keypad = keypad;
	}

	public void execute()
	{
		boolean check = false;
		Screen screen = getScreen();
		BankDatabase bank_database = getBankDatabase();
		while (check != true)
		{
			screen.displayMessage("\n계좌번호 입력: ");
			int account_number = keypad.getInteger();
			boolean check_account = bank_database.checkAccount(account_number);
			if (check_account == false)
			{
				screen.displayMessage("\nPIN 입력: ");
				int pin = keypad.getInteger();
				boolean checkD = bank_database.authenticateUser(account_number, pin);
				if (checkD)
				{
					screen.displayMessage("\n계좌를 삭제합니다.");
					bank_database.deleteAccount(account_number);
					check = true;
					break;
				}
				else
				{
					screen.displayMsgLine("비밀번호가 일치하지 않습니다. 다시입력해주세요.");
				}
			}
			else
				screen.displayMsgLine("일치하는 계좌번호가 없습니다. 다시 입력해 주세요");
		}
	}
}
