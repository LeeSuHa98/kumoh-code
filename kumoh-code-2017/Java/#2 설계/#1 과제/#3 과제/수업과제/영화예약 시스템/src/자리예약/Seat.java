package 자리예약;

import java.util.Scanner;

public class Seat
{
	Scanner sc = new Scanner(System.in);
	final int MAX_ROWS = 10;
	final int MAX_COLS = 10;
	final int MAX_SEAT = (MAX_ROWS * MAX_COLS);
	
	private String[][] seatList;
	private int seatRows;
	private int seatCols;
	
	public Seat()
	{
		this.seatRows = MAX_ROWS;
		this.seatCols = MAX_COLS;
		
		seatList = new String[seatRows][seatCols];
		
		for(int i = 0; i < seatRows; i++)
		{
			for(int j = 0; j < seatCols; j++)
			{
				seatList[i][j] = "0";
			}
		}
	}

	public int getSeatRows() {return seatRows;}
	public int getSeatCols() {return seatCols;}
	public void setSeat(int seatRows, int seatCols, String seatCheck)
	{
		this.seatRows = seatRows;
		this.seatCols = seatCols;
		
		seatList[seatRows][seatCols] = seatCheck;
	}
	public String getSeat(int seatRows, int seatCols) {return seatList[seatRows][seatCols];}
}