package �ڸ�����;

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
			System.out.println("���� �¼��� �����մϴ�.");
			
			System.out.print("�� : ");
			int seatRows = sc.nextInt();
			System.out.print("�� : ");
			int seatCols = sc.nextInt();
			
			if(s.MAX_SEAT <= count)
			{
				throw new MyException(FULL_SEAT);
			}
			else if(s.getSeat(seatRows, seatCols) == UNCHECKED_SEAT) 
			{
				s.setSeat(seatRows, seatCols, CHECKED_SEAT);
				count++;
				System.out.println("���� �Ϸ�");
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
			System.out.println("���� �¼��� ������ ����մϴ�.");
			
			System.out.print("�� : ");
			int seatRows = sc.nextInt();
			System.out.print("�� : ");
			int seatCols = sc.nextInt();
			
			if(s.getSeat(seatRows,seatCols) == UNCHECKED_SEAT) 
			{
				throw new MyException(UNCHECKED_SEAT);
			}
			else 
			{
				s.setSeat(seatRows ,seatCols, UNCHECKED_SEAT);
				System.out.println("���� ��� �Ϸ�");
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
		System.out.println("------------ �¼� ��ġ�� ------------");
		System.out.println("------------ �ű��¼� : 0 ------------");
		System.out.println("------------ �����¼� : 1 ------------");
		System.out.println("�� �¼� : " + s.MAX_SEAT);
		
		for(int i = 0; i < s.MAX_ROWS; i++) 
		{
			for(int j = 0; j < s.MAX_COLS; j++)
			{
				System.out.print(s.getSeat(i,j) + " ");
			}
			System.out.println();
		}	
		
		int sum = (s.MAX_ROWS * s.MAX_COLS) - count;
		System.out.println("�� �¼� : " + sum);
		System.out.println("���� �¼� : " + count);
	}
}
