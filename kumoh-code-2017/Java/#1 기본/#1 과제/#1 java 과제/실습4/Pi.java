import java.util.Scanner;
// [�ǽ� 4 - Repetition]
public class Pi
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		// 1000 �Է� �� PI�� ����� ���ڰ� ����ȴ�.
		System.out.print("������ ���ڸ� �Է��Ͻÿ� : ");
		double num = sc.nextDouble();
		double result = 0;
		double invert = 1;
		
		for(double i = 1; i <= num; i+=2)
		{
			result += invert * 1 / i;
			invert =- invert;
		}
		result = result * 4 ;
		
		System.out.println("��� : " + result);
		
	}
}
