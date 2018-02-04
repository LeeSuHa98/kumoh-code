// [½Ç½À 6 - Command-line argument]
public class SubString
{
	public static void main(String[] args)
	{
		// substring(int beginIndex, int endIndex)
		
		int a = Integer.valueOf(args[1]);
		int b = a + Integer.valueOf(args[2]);
		System.out.println( args[0].substring(a, b) );
	}
}

