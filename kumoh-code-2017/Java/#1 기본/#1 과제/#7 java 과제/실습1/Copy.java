import java.io.*;

public class Copy
{
	public static void main(String[] args) throws IOException
	{
		FileInputStream in = null;
		FileOutputStream out = null;
		
		//1. 스트림 생성
		in = new FileInputStream(args[0]);
		out = new FileOutputStream(args[1]);
		
		//2. 읽기/쓰기 연산 수행
		int c;
		while((c = in.read()) != -1)
		{
			out.write(c);
		}
		
		//3. 스트림 닫기
		in.close();
		out.close();
	}
}
