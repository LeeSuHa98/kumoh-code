// [실습 5 - 배열]
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
			rowSum = 0; // 다음 행의 값을 위하여 초기화
			for(int j : i)
			{
				rowSum = rowSum + j;
				totalSum = totalSum + j;
			}
			System.out.println(rowNum + "행의 합 = " + rowSum);
			rowNum++;
		}
		
		System.out.println("행렬의 총합 : " + totalSum);
	}
}
