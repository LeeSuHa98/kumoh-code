import java.io.*;

public class Demo
{
	public static void main(String[] args)
	{
		int[] units = {12, 8, 13, 29, 50};
		DataOutputStream out = null;
		try
		{
			out = new DataOutputStream(new FileOutputStream("aFile"));
			
			for(int i = 0; i < units.length; i++)
			{
				out.writeInt(units[i]);
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
		finally // 보통 finally에서 파일을 close함.
		{
			try
			{
				if(out != null)
				{
					out.close();
				}
			}
			catch(IOException e){}
		}
	}
}
