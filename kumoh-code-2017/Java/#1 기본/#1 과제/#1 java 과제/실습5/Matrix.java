import java.util.Scanner;
// [�ǽ� 5 - �迭]
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
				System.out.print((i + 1) +  "�� " + (j + 1) + "�� ��: ");
				matrix[i][j] = sc.nextInt();
			}
		}
		
		System.out.println();
		for(int i = 0; i < matrix.length; i++)
		{
			rowSum = 0; // ���� ���� ���� ���Ͽ� �ʱ�ȭ
			for(int j = 0; j < matrix[i].length; j++)
			{
				rowSum = rowSum + matrix[i][j];
				totalSum = totalSum + matrix[i][j];
			}
			System.out.println((i + 1) + "���� �� = " + rowSum);
		}
		
		System.out.println("����� ���� : " + totalSum);
	}
}
