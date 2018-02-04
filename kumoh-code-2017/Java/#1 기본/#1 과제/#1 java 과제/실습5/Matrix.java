import java.util.Scanner;
// [실습 5 - 배열]
public class Matrix
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		final int ROW = 3;
		final int COL = 4;
		
		int rowSum = 0;
		int totalSum = 0;
		
		int[][] matrix = new int[ROW][COL];
		
		for(int i = 0; i < matrix.length; i++)
		{
			for(int j = 0; j < matrix[i].length; j++)
			{
				System.out.print((i + 1) +  "행 " + (j + 1) + "열 값: ");
				matrix[i][j] = sc.nextInt();
			}
		}
		
		System.out.println();
		for(int i = 0; i < matrix.length; i++)
		{
			rowSum = 0; // 다음 행의 값을 위하여 초기화
			for(int j = 0; j < matrix[i].length; j++)
			{
				rowSum = rowSum + matrix[i][j];
				totalSum = totalSum + matrix[i][j];
			}
			System.out.println((i + 1) + "행의 합 = " + rowSum);
		}
		
		System.out.println("행렬의 총합 : " + totalSum);
	}
}
