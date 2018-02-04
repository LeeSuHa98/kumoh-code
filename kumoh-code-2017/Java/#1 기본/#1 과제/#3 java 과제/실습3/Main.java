public class Main
{
	public static void main(String[] args)
	{
		vararg v = new vararg();
		
		int[] numbers1 = {1,2,3,4};
		int[] numbers2 = {1,2,3,4,5,6,7};
		
		int result1 = v.summation(numbers1);
		System.out.println("numbers1 of summation : " + result1);
		int result2 = v.summation(numbers2);
		System.out.println("numbers2 of summation : " + result2);
	}
}
