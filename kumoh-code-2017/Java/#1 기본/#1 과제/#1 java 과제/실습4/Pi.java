import java.util.Scanner;
// [실습 4 - Repetition]
public class Pi
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		// 1000 입력 시 PI에 가까운 숫자가 도출된다.
		System.out.print("임의의 숫자를 입력하시오 : ");
		double num = sc.nextDouble();
		double result = 0;
		double invert = 1;
		
		for(double i = 1; i <= num; i+=2)
		{
			result += invert * 1 / i;
			invert =- invert;
		}
		result = result * 4 ;
		
		System.out.println("결과 : " + result);
		
	}
}
