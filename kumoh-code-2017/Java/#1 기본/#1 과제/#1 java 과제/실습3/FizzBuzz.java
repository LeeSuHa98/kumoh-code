// [실습 3 - Selection]
import java.util.Scanner;

public class FizzBuzz
{	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("------ FizzBuzz 프로그램 ------");
		
		while(true)
		{
			System.out.print("1~ 100 사이의 숫자를 입력하시오 : ");
			int value = sc.nextInt();
			
			if(value > 100 || value < 1 )
			{
				System.out.println("범위에서 벗어난 값입니다. 다시 입력하시오.");
			}
			else if(value % 35 == 0)
			{
				System.out.println("FizzBuzz");
				break;
			}
			else if(value % 5 == 0)
			{
				System.out.println("Fizz");
				break;
			}
			else if(value % 7 == 0)
			{
				System.out.println("Buzz");
				break;
			}
			else
			{
				System.out.println("다시 입력하시오.");
			}
		}
	}
}
