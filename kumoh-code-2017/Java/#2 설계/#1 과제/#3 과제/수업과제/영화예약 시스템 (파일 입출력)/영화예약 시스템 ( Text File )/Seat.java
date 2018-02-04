package 자리예약;

import java.util.Scanner;

public class Seat
{
	Scanner sc = new Scanner(System.in);
	static final int MAX_ROWS = 5;
	static final int MAX_COLS = 5;
	static final int MAX_SEAT = (MAX_ROWS * MAX_COLS);
	static final int UNCHECKED_SEAT = 0;
	static final int CHECKED_SEAT = 1;
	static final int FULL_SEAT = 2;
	
	private int[][] seatList;
	private int seatRows;
	private int seatCols;
	private int count;

	public Seat()
	{
		this.seatRows = MAX_ROWS;
		this.seatCols = MAX_COLS;
		count = 0;
		
		seatList = new int[seatRows][seatCols];
		
		for(int i = 0; i < seatRows; i++)
		{
			for(int j = 0; j < seatCols; j++)
			{
				seatList[i][j] = 0;
			}
		}
	}
	
	public int getCount() { return count; }
	public int getSeatRows() {return seatRows;}
	public int getSeatCols() {return seatCols;}
	public int getSeat(int seatRows, int seatCols) {return seatList[seatRows][seatCols];}
	public void insertSeat(int seatRows, int seatCols, int seatCheck)
	{
		this.seatRows = seatRows;
		this.seatCols = seatCols;
		
		seatList[seatRows][seatCols] = seatCheck;
		
		count++;
	}
	
	public void deleteSeat(int seatRows, int seatCols, int seatCheck)
	{
		this.seatRows = seatRows;
		this.seatCols = seatCols;
		
		seatList[seatRows][seatCols] = seatCheck;
		
		count--;
	}
}