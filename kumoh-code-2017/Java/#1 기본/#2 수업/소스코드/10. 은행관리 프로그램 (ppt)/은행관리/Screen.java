package 은행관리;

public class Screen
{
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
