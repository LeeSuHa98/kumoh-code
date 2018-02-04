// [�ǽ� 3 - Selection]
import java.util.Scanner;

public class FizzBuzz
{	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("------ FizzBuzz ���α׷� ------");
		
		while(true)
		{
			System.out.print("1~ 100 ������ ���ڸ� �Է��Ͻÿ� : ");
			int value = sc.nextInt();
			
			if(value > 100 || value < 1 )
			{
				System.out.println("�������� ��� ���Դϴ�. �ٽ� �Է��Ͻÿ�.");
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
				System.out.println("�ٽ� �Է��Ͻÿ�.");
			}
		}
	}
}
