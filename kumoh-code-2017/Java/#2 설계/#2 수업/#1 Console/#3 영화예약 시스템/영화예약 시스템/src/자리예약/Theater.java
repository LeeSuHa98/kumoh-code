package 자리예약;

import java.util.Scanner;

public class Theater
{
	Scanner sc = new Scanner(System.in);
	Seat s = new Seat();
	
	final String UNCHECKED_SEAT = "0";
	final String CHECKED_SEAT = "1";
	final String FULL_SEAT = "2";
	
	private int count;
	
	public Theater()
	{
		count = 0;
	}
	
	public void reservationTheater()
	{
		try
		{
			System.out.println("극장 좌석을 예약합니다.");
			
			System.out.print("행 : ");
			int seatRows = sc.nextInt();
			System.out.print("열 : ");
			int seatCols = sc.nextInt();
			
			if(s.MAX_SEAT <= count)
			{
				throw new MyException(FULL_SEAT);
			}
			else if(s.getSeat(seatRows, seatCols) == UNCHECKED_SEAT) 
			{
				s.setSeat(seatRows, seatCols, CHECKED_SEAT);
				count++;
				System.out.println("예약 완료");
			}
			else 
			{
				throw new MyException(CHECKED_SEAT);
			}
		}
		catch(MyException e) 
		{
			e.message();
		}
	}
	
	public void cancelTheater()
	{	
		try 
		{
			System.out.println("극장 좌석의 예약을 취소합니다.");
			
			System.out.print("행 : ");
			int seatRows = sc.nextInt();
			System.out.print("열 : ");
			int seatCols = sc.nextInt();
			
			if(s.getSeat(seatRows,seatCols) == UNCHECKED_SEAT) 
			{
				throw new MyException(UNCHECKED_SEAT);
			}
			else 
			{
				s.setSeat(seatRows ,seatCols, UNCHECKED_SEAT);
				System.out.println("예약 취소 완료");
				count--;
			}
		}
		catch(MyException e)
		{
			e.message();
		}
	}
	
	public void displayTheater()
	{
		System.out.println("------------ 좌석 배치도 ------------");
		System.out.println("------------ 신규좌석 : 0 ------------");
		System.out.println("------------ 예약좌석 : 1 ------------");
		System.out.println("총 좌석 : " + s.MAX_SEAT);
		
		for(int i = 0; i < s.MAX_ROWS; i++) 
		{
			for(int j = 0; j < s.MAX_COLS; j++)
			{
				System.out.print(s.getSeat(i,j) + " ");
			}
			System.out.println();
		}	
		
		int sum = (s.MAX_ROWS * s.MAX_COLS) - count;
		System.out.println("빈 좌석 : " + sum);
		System.out.println("예약 좌석 : " + count);
	}
}
