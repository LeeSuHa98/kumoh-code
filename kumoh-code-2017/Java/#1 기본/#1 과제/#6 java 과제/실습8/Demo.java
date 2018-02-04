import java.io.*;
import java.util.Scanner;

public class Demo
{
	public static void divide(int a, int b) throws Exception
	{
		int result = a/b;
		System.out.println("��� : " + result);
	}
	
	public static void main(String[] args)
	{
		try
		{
			Scanner sc = new Scanner(System.in);
			System.out.println("������ ���� 2���� �Է��Ͻÿ�. ");
			System.out.print("ù ��° ���� : ");
			int a = sc.nextInt();
			System.out.print("�� ��° ���� : ");
			int b = sc.nextInt();
			
			divide(a, b);
		}
		catch(Exception e) // Stack trace ���� ����
		{
			StackTraceElement[] elements = e.getStackTrace();
			
			for(StackTraceElement x : elements)
			{
				System.err.println(x.getFileName() + ":" + x.getLineNumber() + ">>" + x.getMethodName() + "()");
			}
		}
	}
}
