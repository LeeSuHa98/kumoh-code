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
			System.out.println("���� �������� ����.");
		}
		catch(IOException e)
		{
			System.out.println("���� ������ ����.");
		}
		finally // ���� finally���� ������ close��.
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
