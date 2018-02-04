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
			while((c = in.read()) != -1) // EOF 검사
			{
				out.write(c);
			}
		}
		catch(FileNotFoundException e)
		{
			System.out.println("파일 존재하지 않음.");
		}
		catch(IOException e)
		{
			System.out.println("쓰기 방지된 파일.");
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
