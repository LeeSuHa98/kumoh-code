import java.io.*;
import java.util.Scanner;

public class Demo
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int a;
		int b;
		int x; // result
		
		System.out.print("������ ù��° ������ �Է��Ͻÿ�  : ");
		a = sc.nextInt();
		
		System.out.print("������ �ι�° ������ �Է��Ͻÿ�  : ");
		b = sc.nextInt();
		
		try
		{
			x = a/b;
			System.out.println("��� : " + x);
		}
		catch(ArithmeticException e)
		{
			e.printStackTrace();
		}
	}
}
