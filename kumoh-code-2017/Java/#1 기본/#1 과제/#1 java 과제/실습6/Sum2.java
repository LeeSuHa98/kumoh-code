//[실습 6 - Command-line argument]
import java.util.Scanner;

public class Sum2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		final int MAX_COUNT = 10;
		
		float floatSum = 0.0f;
		int intSum = 0;
		
		int count = 1;
		float value;
		float[] arr = new float[MAX_COUNT];
		
		System.out.print("임의의 숫자를 입력하시오(-1 입력시 종료) : ");
		for(int i = 0; i < count; i++)
		{
			value = sc.nextFloat();
			
			if(value == -1)
			{
				break;
			}
			arr[i] = value;
			
			count++;
		}
		
		for(int i = 0; i < count; i++)
		{
			floatSum = floatSum + arr[i];
			intSum = (int)floatSum;
		}
		
		System.out.println("실수의 합 : " + floatSum  + " 정수의 합 :" + intSum);
	}
}
