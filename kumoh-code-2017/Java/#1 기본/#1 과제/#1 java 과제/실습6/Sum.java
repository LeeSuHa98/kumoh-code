//[�ǽ� 6 - Command-line argument]
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
		System.out.format("�Ǽ��� �� = %10.5f", floatSum);
		System.out.println();
		System.out.format("������ �� = %d", intSum);
	}
}
