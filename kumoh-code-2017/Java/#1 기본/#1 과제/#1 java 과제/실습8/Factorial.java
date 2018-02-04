public class Factorial
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
		long tmp = 1;
		for(int i = 1; i <= x; i++)
		{
			tmp = tmp * i;
		}
		
		return tmp;
	}
}