import java.util.Scanner;

public class Keypad
{
	private Scanner keyboard;
	
	public Keypad()
	{
		keyboard = new Scanner(System.in);
	}
	
	public int getInteger() // Ű����κ��� ������ ��ȯ
	{
		return keyboard.nextInt();
	}
	
	public String getString() // Ű����κ��� ���ڿ��� ��ȯ
	{
		return keyboard.next();
	}
}

