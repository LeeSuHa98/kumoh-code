import java.io.*;
import java.util.Scanner;

public class Demo
{
	public static int divide(int a, int b) throws ArithmeticException
	{
		return a/b;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int a;
		int b;
		int x; // result
		
		System.out.print("임의의 첫번째 정수를 입력하시오  : ");
		a = sc.nextInt();
		
		System.out.print("임의의 두번째 정수를 입력하시오  : ");
		b = sc.nextInt();
		
		x = divide(a,b);
		System.out.println("결과 : " + x);
	}
}
