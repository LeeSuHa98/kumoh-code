import java.io.*;

public class Demo
{
	public static void main(String[] args)
	{
		int[] units = {12, 8, 13, 29, 50};
		try(DataOutputStream out = new DataOutputStream(new FileOutputStream("aFile"));)
		{	
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
	}
}
