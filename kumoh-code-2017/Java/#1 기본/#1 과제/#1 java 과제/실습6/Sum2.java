//[�ǽ� 6 - Command-line argument]
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
		
		System.out.print("������ ���ڸ� �Է��Ͻÿ�(-1 �Է½� ����) : ");
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
		
		System.out.println("�Ǽ��� �� : " + floatSum  + " ������ �� :" + intSum);
	}
}
