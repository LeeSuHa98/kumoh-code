// [�ǽ� 5 - �迭]
public class Matrix2
{
	public static void main(String[] args)
	{
		int rowSum = 0;
		int totalSum = 0;
		int rowNum = 1;
		
		int[][] matrix = {	{1,2,3,4},
							{5,6,7,8},
							{9,10,11,12}};
		
		for(int i[] : matrix)
		{
			rowSum = 0; // ���� ���� ���� ���Ͽ� �ʱ�ȭ
			for(int j : i)
			{
				rowSum = rowSum + j;
				totalSum = totalSum + j;
			}
			System.out.println(rowNum + "���� �� = " + rowSum);
			rowNum++;
		}
		
		System.out.println("����� ���� : " + totalSum);
	}
}
