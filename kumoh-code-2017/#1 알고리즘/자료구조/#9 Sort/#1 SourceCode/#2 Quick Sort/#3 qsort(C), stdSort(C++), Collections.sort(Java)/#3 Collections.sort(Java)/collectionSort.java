import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Comparator;

public class collectionSort
{
	public static void main(String[] args)
	{
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		FileHandler fh = new FileHandler();
		
		try {
			fh.loadFile("QSortData.txt", list);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		long start = System.currentTimeMillis();
		Collections.sort(list);
		long end = System.currentTimeMillis();

		double sortTime = ( end - start ) / 1000.0;
		System.out.println( "실행 시간 : " + sortTime );

		double sortTimeStr = sortTime;
		
		String sortName = "QSortData_Java.txt";
		try
		{
			fh.saveFile(sortName + " 결과( " + sortTimeStr + " ).txt", list);
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}

class FileHandler
{
	public FileHandler(){}
	
	public void loadFile(String fileName, ArrayList<Integer> list) throws IOException
	{
		FileReader fr = null;
		
		try
		{			
			fr = new FileReader(fileName);
			BufferedReader br = new BufferedReader(fr);
			
			String str = "";
			while((str = br.readLine()) != null)
			{
				int value = Integer.valueOf(str);
				list.add(value);
			}
			
			fr.close();
			
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
			fr.close();
		}
	
	}
	
	public void saveFile(String fileName, ArrayList<Integer> list) throws IOException
	{
		FileWriter fw = null;
		
		try
		{
			fw = new FileWriter(fileName);
			BufferedWriter bw = new BufferedWriter(fw);
			
			for(int i = 0; i < list.size(); ++i)
			{
				fw.write(list.get(i));
			}
			
			fw.close();
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
			fw.close();
		}
	}
}