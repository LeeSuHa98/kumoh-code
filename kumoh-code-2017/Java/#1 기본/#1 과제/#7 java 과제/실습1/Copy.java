import java.io.*;

public class Copy
{
	public static void main(String[] args) throws IOException
	{
		FileInputStream in = null;
		FileOutputStream out = null;
		
		//1. ��Ʈ�� ����
		in = new FileInputStream(args[0]);
		out = new FileOutputStream(args[1]);
		
		//2. �б�/���� ���� ����
		int c;
		while((c = in.read()) != -1)
		{
			out.write(c);
		}
		
		//3. ��Ʈ�� �ݱ�
		in.close();
		out.close();
	}
}
