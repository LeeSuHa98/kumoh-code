package 자리예약;

import java.io.IOException;
import java.util.Scanner;

public class Theater
{
	Scanner sc = new Scanner(System.in);
	FileHandler fh = new FileHandler();
	Seat s = new Seat();
	
	public void reservationTheater()
	{
		try
		{
			System.out.println("극장 좌석을 예약합니다.");
			
			System.out.print("행 : ");
			int seatRows = sc.nextInt();
			System.out.print("열 : ");
			int seatCols = sc.nextInt();
			
			if(Seat.MAX_SEAT <= s.getCount())
			{
				throw new MyException(Seat.FULL_SEAT);
			}
			else if(s.getSeat(seatRows, seatCols) == Seat.UNCHECKED_SEAT) 
			{
				s.insertSeat(seatRows, seatCols, Seat.CHECKED_SEAT);
				System.out.println("예약 완료");
			}
			else 
			{
				throw new MyException(Seat.CHECKED_SEAT);
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
			
			if(s.getSeat(seatRows,seatCols) == Seat.UNCHECKED_SEAT) 
			{
				throw new MyException(Seat.UNCHECKED_SEAT);
			}
			else 
			{
				s.deleteSeat(seatRows ,seatCols, Seat.UNCHECKED_SEAT);
				System.out.println("예약 취소 완료");
				s.getCount();
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
		System.out.println("총 좌석 : " + Seat.MAX_SEAT);
		
		for(int i = 0; i < Seat.MAX_ROWS; i++) 
		{
			for(int j = 0; j < Seat.MAX_COLS; j++)
			{
				System.out.print(s.getSeat(i,j) + " ");
			}
			System.out.println();
		}	
		
		int sum = (Seat.MAX_ROWS * Seat.MAX_COLS) - s.getCount();
		System.out.println("빈 좌석 : " + sum);
		System.out.println("예약 좌석 : " + s.getCount());
	}
	
	public void loadTheater(String fileName) throws IOException
	{
		try
		{
			fh.loadSeat(fileName, s);
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
	
	public void saveTheater(String fileName) throws IOException
	{
		try
		{
			fh.saveSeat(fileName, s);
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}
