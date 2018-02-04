import java.util.Scanner;

public class AvgSum2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		final int MAX_COUNT = 10;
		int intSum = 0;
		float floatSum = 0.0f;
		
		int intCount = 0;
		int floatCount = 0;
		
		int[] intArr = new int[MAX_COUNT];
		float[] floatArr = new float[MAX_COUNT];
		
		System.out.print("���ڸ� �Է��Ͻÿ�(-1 �Է½� ����) : ");
		while(!sc.hasNext("-1"))
		{
			if(sc.hasNextInt())
				intArr[intCount++] = sc.nextInt();
			
			else if(sc.hasNextFloat())
				floatArr[floatCount++] = sc.nextFloat();
		}
		
		for(int i = 0; i < intCount; i++)
		{
			intSum = intSum + intArr[i]; 
		}
		
		for(int j = 0; j < floatCount; j++)
		{
			floatSum = floatSum + floatArr[j];
		}
		
		System.out.println("���� �� :" + intSum);
		System.out.println("�Ǽ� �� :" + floatSum);
	}
}
