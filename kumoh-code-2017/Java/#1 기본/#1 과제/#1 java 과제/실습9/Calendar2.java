import java.util.Scanner;

public class Calendar2
{
	public static void main(String[] args)
	{
		int year;
		int day = 1;
		int month = 1;
		Scanner sc = new Scanner(System.in);
		
		do
		{
			System.out.print("year : ");
			year = sc.nextInt();
		} while(year < 1900);
		
		printDay(year, month, day);
	}
	
	public static void printDay(int year, int month, int day)
	{
		char day_of_week = dayOfDate(year, month, day);
		
		System.out.println(year + "년 " + month + "월 " + day + "일은 " + day_of_week + "요일입니다.");
	}
	
	public static int monthDays(int year, int month)
	{
		int day_of_month = 0;
		
		Boolean isLeapYear = ((year % 4) == 0) && (year % 100 != 0) || year % 400 == 0;
		
		Boolean is31 = (month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12);
		
		if(isLeapYear && month == 2)
		{
			day_of_month = 29;
		}
		else if(!isLeapYear && month == 2)
		{
			day_of_month = 28;
		}
		else if (is31)
		{
			day_of_month = 31;
		}
		else
		{
			day_of_month = 30;
		}
		return day_of_month;
	}
	
	public static char dayOfDate(int year, int month, int day)
	{
		char day_of_week = 0;
		int total_day = 0;
		
		for(int i = 1900; i <= year; i++)
		{
			if(i < year)
			{
				for(int j = 1; j <= 12; j++)
				{
					total_day += monthDays(i,j);
				}
			}
			else
			{
				for(int j = 1; j < month; j++)
				{
					total_day += monthDays(i,j);
				}
			}
		}
		
		total_day += day;
		
		switch(total_day % 7)
		{
		case 0:
			day_of_week = '일';
			break;
		case 1:
			day_of_week = '월';
			break;
		case 2:
			day_of_week = '화';
			break;
		case 3:
			day_of_week = '수';
			break;
		case 4:
			day_of_week = '목';
			break;
		case 5:
			day_of_week = '금';
			break;
		case 6:
			day_of_week = '토';
			break;
		}
		
		return day_of_week;
	}
}