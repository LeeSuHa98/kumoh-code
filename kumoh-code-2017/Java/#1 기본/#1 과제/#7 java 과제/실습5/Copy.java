import java.io.*;

public class Copy
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = null;
		PrintWriter out = null;
		
		try
		{
			in = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new FileWriter("out.txt"));
			String s;

			while ((s = in.readLine()) != null) // ���� ���� �Է�, EOF �˻�
			{
				out.println(s); // ���� ���� ���: �� OS�� line terminator�� ���� ���� �߰���
			}
		}
		finally
		{
			if(in != null) in.close();
			if(out != null) out.close();
		}
	}
}
