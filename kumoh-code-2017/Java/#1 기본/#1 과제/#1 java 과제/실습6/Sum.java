//[실습 6 - Command-line argument]
public class Sum
{
	public static void main(String[] args)
	{
		float floatSum = 0.0f;
		int intSum = 0;
		
		for(int i = 0; i < args.length; i++)
		{
			floatSum += Float.valueOf(args[i]);
			intSum = (int)floatSum;
		}
		System.out.format("실수의 합 = %10.5f", floatSum);
		System.out.println();
		System.out.format("정수의 합 = %d", intSum);
	}
}
