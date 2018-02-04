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

			while ((s = in.readLine()) != null) // 라인 단위 입력, EOF 검사
			{
				out.println(s); // 라인 단위 출력: 現 OS의 line terminator를 라인 끝에 추가함
			}
		}
		finally
		{
			if(in != null) in.close();
			if(out != null) out.close();
		}
	}
}
