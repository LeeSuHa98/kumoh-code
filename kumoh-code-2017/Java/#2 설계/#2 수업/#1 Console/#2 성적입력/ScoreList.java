import java.util.Scanner;

public class ScoreList
{
	Scanner sc = new Scanner(System.in);
	
	final int MAX_SIZE = 100;
	private Score[] scoreList;
	private int count;
	
	public ScoreList()
	{
		scoreList = new Score[MAX_SIZE];
		count = 0;
	}
	
	public void registerScore()
	{
		System.out.print("Score : ");
		int score = sc.nextInt();

		Score s = new Score(score);
		
		scoreList[count++] = s;
	}
	
	public void displayScore()
	{
		for(int i = 0; i < count; i++)
		{
			System.out.println(i+1 + " of Score : " + scoreList[i].getScore());
		}
		System.out.println("MaxScore : " + maxScore());
		System.out.println("MinScore : " + minScore());
		System.out.println("Average : " + avgScore());
	}
	// 최대값, 최소값, 평균 구현하는 Method 구현하기
	public double maxScore()
	{
		double max = scoreList[0].getScore();
		for(int i = 0; i < count; i++)
		{
			if(max < scoreList[i].getScore())
			{
				max = scoreList[i].getScore();
			}
		}
		return max;
	}
	
	public double minScore()
	{
		double min = scoreList[0].getScore();
		for(int i = 0; i < count; i++)
		{
			if(min > scoreList[i].getScore())
			{
				min = scoreList[i].getScore();
			}
		}
		return min;
	}
	
	public double avgScore()
	{
		double sum = 0;
		for(int i = 0; i < count; i++)
		{
			sum = sum + scoreList[i].getScore();
		}
		return sum / count;	
	}
}
