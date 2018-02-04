package �������;

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
			screen.displayMessage("\n���¹�ȣ �Է�: ");
			int account_number = keypad.getInteger();
			boolean check_account = bank_database.checkAccount(account_number);
			if (check_account == false)
			{
				screen.displayMessage("\nPIN �Է�: ");
				int pin = keypad.getInteger();
				boolean checkD = bank_database.authenticateUser(account_number, pin);
				if (checkD)
				{
					screen.displayMessage("\n���¸� �����մϴ�.");
					bank_database.deleteAccount(account_number);
					check = true;
					break;
				}
				else
				{
					screen.displayMsgLine("��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ��Է����ּ���.");
				}
			}
			else
				screen.displayMsgLine("��ġ�ϴ� ���¹�ȣ�� �����ϴ�. �ٽ� �Է��� �ּ���");
		}
	}
}
