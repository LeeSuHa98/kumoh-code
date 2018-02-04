import java.util.Scanner;

public class FizzBuzz2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("------ FizzBuzz 프로그램 ------");

		while(true)
		{
			System.out.print("1~ 100 사이의 숫자를 입력하시오 : ");
			int value = sc.nextInt();

			if(value > 100 || value < 0 )
			{
				System.out.println("범위에서 벗어난 값입니다. 다시 입력하시오.");
			}

			switch(value % 35)
			{
			case 0:
				System.out.println("FizzBuzz");
				System.exit(1);
			case 5: case 10: case 15: case 20: case 25: case 30:
				System.out.println("Fizz");
				System.exit(1);
			case 7: case 14: case 21: case 28:
				System.out.println("Buzz");
				System.exit(1);
			default:
				System.out.println("다시 입력하시오.");
			}
		}
	}
}
