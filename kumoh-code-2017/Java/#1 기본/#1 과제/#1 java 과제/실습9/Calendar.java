import java.util.Scanner;

public class Calendar
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("년도 : ");
		int input_year = sc.nextInt();

		checkLeapYear(input_year);
	}

	public static void checkLeapYear(int year) 
	{
		boolean leap_year = false;

		if( (0 == (year % 4) && 0 != (year %100)) || 0 == year%400 )
		{
			leap_year = true;
		}
		else
		{
			leap_year = false;
		}
		
		if(leap_year)
		{
			System.out.println(year + "는 윤년입니다. ");
		}
		else
		{
			System.out.println(year + "는 윤년이 아닙니다. ");      
		}  
	}   
}