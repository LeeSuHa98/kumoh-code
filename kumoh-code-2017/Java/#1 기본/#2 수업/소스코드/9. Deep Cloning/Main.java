package 수업;

import java.util.Scanner;

public class Main
{
	public static void main(String[] args) throws CloneNotSupportedException
	{
		Scanner sc = new Scanner(System.in);
		Account x, y;
		
		x = new Account("Son", 100);
		y = new Account("Son", 100);
		
		System.out.println(x.equals(y));
		
		y = x;
		
		System.out.println(x.equals(y));
		
		y = (Account)x.clone();
		
		System.out.println(x.equals(y));
		
		sc.close();
	}
}
