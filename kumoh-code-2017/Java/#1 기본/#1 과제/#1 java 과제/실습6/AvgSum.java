//[�ǽ� 6 - Command-line argument]
public class AvgSum
{
	public static void main(String[] args)
	{
		float avg = 0.0f;
		float sum = 0.0f;
		
		for(int i = 0; i < args.length; i++)
		{
			sum += Float.valueOf(args[i]);
		}
		avg = sum / args.length;

		System.out.format("��� = %10.5f , �� = %10.5f", avg, sum);
	}
}
