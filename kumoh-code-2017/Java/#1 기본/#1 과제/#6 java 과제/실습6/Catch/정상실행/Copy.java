import java.io.*;

public class Copy
{
	public static void main(String[] args) throws IOException
	{
		FileReader in = null;
		FileWriter out = null;
		try
		{
			in = new FileReader("sourceFile.txt");
			out = new FileWriter("targetFile.txt");
			
			int c;
			while((c = in.read()) != -1) // EOF �˻�
			{
				out.write(c);
			}
		}
		catch(FileNotFoundException e)
		{
			System.out.println("���� �������� ����.");
		}
		catch(IOException e)
		{
			System.out.println("���� ������ ����.");
		}
		finally
		{
			try
			{
				if(out != null)
				{
					in.close();
					out.close();
				}
			}
			catch(IOException e){}
		}
	}
}
