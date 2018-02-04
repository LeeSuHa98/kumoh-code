//[실습 4 - Repetition]
public class Repetition2
{
	public static void main(String[] args)
	{
		int count = 1;
		for(int i = 1; i <= 4; i++)
		{
			// 공백
			for(int j = 0; j <= 3-i; j++)
			{
				System.out.printf("   ");
			}
			// count를 순차적으로 반복
			for(int k = 1; k < (i*2); k++)
			{
				System.out.printf("%3d", count++);
			}
			System.out.println();
		}
	}
}
