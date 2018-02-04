package 은행관리;

public class Screen
{
	private Keypad keypad;
	
	public Screen()
	{
		keypad = new Keypad();
	}
	public int displayMainMenu() // main menu display & return select to user
	{
		displayMsgLine("\nMain menu:");
		displayMsgLine("1 - Create Account");
		displayMsgLine("2 - Display Account");
		displayMsgLine("3 - Delete Account");
		displayMsgLine("4 - Check Account");
		displayMsgLine("5 - Exit\n");
		displayMessage("Enter a choice: ");
		
		return keypad.getInteger();
	}
	
	public int displayWorkMenu() // work menu display & return select to user
	{
		displayMsgLine("\nWork menu:");
		displayMsgLine("1 - View my balance");
		displayMsgLine("2 - Withdraw cash");
		displayMsgLine("3 - Deposit funds");
		displayMsgLine("4 - Menu Return");
		displayMsgLine("5 - Exit\n");
		displayMessage("Enter a choice: ");
		
		return keypad.getInteger();
	}
	
	public int displayAccountMenu() // account menu display & return select to user
	{
		displayMsgLine("\nAccount menu:");
		displayMsgLine("1 - Normal Account");
		displayMsgLine("2 - Free Account");
		displayMsgLine("3 - Minus Account");
		displayMsgLine("4 - Exit\n");
		displayMessage("Enter a choice: ");
		
		return keypad.getInteger();
	}
	
	public void displayMessage(String msg)
	{
		System.out.print(msg);
	}
	
	public void displayMsgLine(String msg)
	{
		System.out.println(msg);
	}
	
	public void displayAmount(double amount)
	{
		System.out.printf("%10f", amount);
	}
}
