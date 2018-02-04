import java.io.*;
import java.util.Scanner;

public class Demo
{
	public static void divide(int a, int b) throws Exception
	{
		int result = a/b;
		System.out.println("결과 : " + result);
	}
	
	public static void main(String[] args)
	{
		try
		{
			Scanner sc = new Scanner(System.in);
			System.out.println("임의의 정수 2개를 입력하시오. ");
			System.out.print("첫 번째 정수 : ");
			int a = sc.nextInt();
			System.out.print("두 번째 정수 : ");
			int b = sc.nextInt();
			
			divide(a, b);
		}
		catch(Exception e) // Stack trace 정보 접근
		{
			StackTraceElement[] elements = e.getStackTrace();
			
			for(StackTraceElement x : elements)
			{
				System.err.println(x.getFileName() + ":" + x.getLineNumber() + ">>" + x.getMethodName() + "()");
			}
		}
	}
}
