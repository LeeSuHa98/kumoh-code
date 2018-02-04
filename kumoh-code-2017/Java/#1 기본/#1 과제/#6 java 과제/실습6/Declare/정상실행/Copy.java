import java.io.*;

public class Copy
{
	public static void mX() throws IOException
	{
		FileReader in = null;
		FileWriter out = null;
		
		in = new FileReader("sourceFile.txt");
		out = new FileWriter("targetFile.txt");
		
		int c;
		while((c = in.read()) != -1) // EOF °Ë»ç
		{
			out.write(c);
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws IOException
	{
		mX();
	}
}
