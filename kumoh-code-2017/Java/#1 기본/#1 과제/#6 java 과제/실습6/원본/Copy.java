import java.io.*;

public class Copy
{
	public static void main(String[] args) throws IOException
	{
		FileReader in = null;
		FileWriter out = null;
		in = new FileReader("sourceFile");
		out = new FileWriter("targetFile");
		
		int c;
		while((c = in.read()) != -1) // EOF °Ë»ç
		{
			out.write(c);
		}
		in.close();
		out.close();
	}
}
