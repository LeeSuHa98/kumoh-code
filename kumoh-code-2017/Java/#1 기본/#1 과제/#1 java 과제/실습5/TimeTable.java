import java.util.Scanner;
// [실습 5 - 배열]
public class TimeTable
{
	public static void main(String[] args)
	{
		int set;			// 한 줄에 몇개의 단을 출력할 것인지 저장.
		final int WIDTH = 3;		// 숫자 하나의 너비
		final int LAST = 9;		// 마지막 출력 단수
		
		Scanner sc = new Scanner(System.in);
		
		while(true)
		{
			System.out.println("한 줄에 몇개의 단을 출력하시겠습니까?(1 ~ 8)");
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
