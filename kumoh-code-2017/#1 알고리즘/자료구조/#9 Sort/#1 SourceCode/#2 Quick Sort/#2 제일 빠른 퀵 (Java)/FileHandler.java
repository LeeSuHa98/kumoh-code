import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class FileHandler
{
	public FileHandler(){}
	
	public void loadFile(String fileName, ArrayList<String> list) throws IOException
	{
		FileReader fr = null;
		
		try
		{			
			fr = new FileReader(fileName);
			BufferedReader br = new BufferedReader(fr);
			
			String str = "";
			while((str = br.readLine()) != null)
			{
				String value = str;
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
	
	public void saveFile(String fileName, ArrayList<String> list) throws IOException
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
