import java.io.*;

public class Delete
{
	public static void main(String[] args)
	{
		try
		{
			File f = new File(args[0]);
			
			if(!f.exists())
			{
				throw new IllegalArgumentException("���� ����: " + args[0]);
			}
			if(!f.canWrite())
			{
				throw new IllegalArgumentException("���� ����: " + args[0]);
			}
			if(f.isDirectory() && f.list().length>0)
			{
				throw new IllegalArgumentException("�� ���丮 �ƴ�: " + args[0]);
			}
			if(!f.delete())
			{
				throw new IllegalArgumentException("���� ����: ");
			}
		}
		catch(IllegalArgumentException e)
		{
			System.out.println(e.getMessage());
		}
	}
}
