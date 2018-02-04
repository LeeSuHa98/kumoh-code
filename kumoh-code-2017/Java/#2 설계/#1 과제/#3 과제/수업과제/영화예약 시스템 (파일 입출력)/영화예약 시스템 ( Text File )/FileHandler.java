package 자리예약;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
//import java.io.BufferedReader;
//import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class FileHandler
{
	public void loadSeat(String fileName, Seat s) throws IOException
	{
		try
		{
			//		FileReader fr = new FileReader(fileName);
			//		
			//		BufferedReader br = new BufferedReader(fr);

			FileInputStream fin = new FileInputStream(fileName);
			InputStreamReader in = new InputStreamReader(fin);
			int text;

			for(int i = 0; i < Seat.MAX_ROWS; i++)
			{
				for(int j = 0; j < Seat.MAX_COLS; j++)
				{
					text = in.read();
					s.insertSeat(i, j, text);
				}
			}
			System.out.println("파일을 불러옵니다.");
			in.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}

	public void saveSeat(String fileName, Seat s) throws IOException
	{
		try
		{
//			PrintWriter pw = new PrintWriter(fileName);
			
			FileOutputStream fout = new FileOutputStream(fileName);
			OutputStreamWriter out = new OutputStreamWriter(fout);
			
			for(int i = 0; i < Seat.MAX_ROWS; i++)
			{
				for(int j = 0; j < Seat.MAX_COLS; j++)
				{
					out.write(s.getSeat(i,j) + " ");		
				}
			}
			System.out.println("파일을 저장합니다.");
			out.close();
		}
		catch(IOException e) 
		{
			e.printStackTrace();
		}
	}
}
