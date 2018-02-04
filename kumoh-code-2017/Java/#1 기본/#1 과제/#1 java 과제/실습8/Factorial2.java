public class Factorial2
{
	public static void main(String[] args)
	{
		long result = 1;
		
		for(int i = 0; i < args.length; i++)
		{
			result = Integer.parseInt(args[i]);
		}
		
		System.out.format("%d", factorial(result));
	}
	
	public static long factorial(long x)
	{
		if (x > 1)
		{
			return x * factorial(x-1);
		}
		else
		{
			return x;
		}
	}
}
