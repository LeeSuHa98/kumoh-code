package 은행관리;

import java.util.Scanner;

public class Keypad
{
	private Scanner keyboard;
	
	public Keypad()
	{
		keyboard = new Scanner(System.in);
	}
	
	public int getInteger() // 키보드로부터 정수를 반환
	{
		return keyboard.nextInt();
	}
	
	public String getString() // 키보드로부터 문자열을 반환
	{
		return keyboard.next();
	}
}
