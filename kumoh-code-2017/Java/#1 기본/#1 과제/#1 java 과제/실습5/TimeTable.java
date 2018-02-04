import java.util.Scanner;
// [�ǽ� 5 - �迭]
public class TimeTable
{
	public static void main(String[] args)
	{
		int set;			// �� �ٿ� ��� ���� ����� ������ ����.
		final int WIDTH = 3;		// ���� �ϳ��� �ʺ�
		final int LAST = 9;		// ������ ��� �ܼ�
		
		Scanner sc = new Scanner(System.in);
		
		while(true)
		{
			System.out.println("�� �ٿ� ��� ���� ����Ͻðڽ��ϱ�?(1 ~ 8)");
			System.out.print("> ");
			set = sc.nextInt();
			if (1 <= set && set <= 8) break;
		}
		System.out.println();

		for (int i = 2; i <= 9; i += set)
		{
			for (int j = 1; j <= 9; ++j)
			{
				for (int k = i; k < i + set; ++k)
				{
					if (k <= LAST) 
					System.out.printf("%" + WIDTH + "d *%" + WIDTH +"d =%" + WIDTH + "d   ", k, j, k * j);
				}
				System.out.println();
			}
			System.out.println();
		}
	}
}
