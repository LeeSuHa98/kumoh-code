import java.io.*;
import java.util.Scanner;

public class Demo
{
	public static void methodA()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("임의의 정수 2개를 입력하시오. ");
		System.out.print("첫 번째 정수 : ");
		int a = sc.nextInt();
		System.out.print("두 번째 정수 : ");
		int b = sc.nextInt();
		
		methodB(a,b);
	}
	
	public static void methodB(int a, int b)
	{
		try
		{
			int result = a/b; // 0으로 나눌 시 예외 발생
			System.out.println("결과 : " + result);
		}
		catch(Exception e)
		{
			System.out.println("발생한 곳에서 예외 처리");
		}
	}
	public static void main(String[] args)
	{
		methodA();
	}
}
