// [�ǽ� 4 - Repetition]
public class Repetition
{
	public static void main(String[] args)
	{
		for(int i = 1; i <= 4; i++)
		{
			// ����
			for(int j = 0; j <= 3-i; j++)
			{
				System.out.print("   ");
			}
			// 1���� �ݺ�
			for(int k = i; k > 1; k--)
			{
				System.out.printf("%3d", k);
			}
			// 1���� �ݺ�
			for(int j = 1; j <= i; j++)
			{
				System.out.printf("%3d", j);
			}
			System.out.println();
		}
	}
}