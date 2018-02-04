package �ڸ�����;

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
			System.out.println("���� �¼��� �����մϴ�.");
			
			System.out.print("�� : ");
			int seatRows = sc.nextInt();
			System.out.print("�� : ");
			int seatCols = sc.nextInt();
			
			if(Seat.MAX_SEAT <= s.getCount())
			{
				throw new MyException(Seat.FULL_SEAT);
			}
			else if(s.getSeat(seatRows, seatCols) == Seat.UNCHECKED_SEAT) 
			{
				s.insertSeat(seatRows, seatCols, Seat.CHECKED_SEAT);
				System.out.println("���� �Ϸ�");
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
			System.out.println("���� �¼��� ������ ����մϴ�.");
			
			System.out.print("�� : ");
			int seatRows = sc.nextInt();
			System.out.print("�� : ");
			int seatCols = sc.nextInt();
			
			if(s.getSeat(seatRows,seatCols) == Seat.UNCHECKED_SEAT) 
			{
				throw new MyException(Seat.UNCHECKED_SEAT);
			}
			else 
			{
				s.deleteSeat(seatRows ,seatCols, Seat.UNCHECKED_SEAT);
				System.out.println("���� ��� �Ϸ�");
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
		System.out.println("------------ �¼� ��ġ�� ------------");
		System.out.println("------------ �ű��¼� : 0 ------------");
		System.out.println("------------ �����¼� : 1 ------------");
		System.out.println("�� �¼� : " + Seat.MAX_SEAT);
		
		for(int i = 0; i < Seat.MAX_ROWS; i++) 
		{
			for(int j = 0; j < Seat.MAX_COLS; j++)
			{
				System.out.print(s.getSeat(i,j) + " ");
			}
			System.out.println();
		}	
		
		int sum = (Seat.MAX_ROWS * Seat.MAX_COLS) - s.getCount();
		System.out.println("�� �¼� : " + sum);
		System.out.println("���� �¼� : " + s.getCount());
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
