import java.io.*;
import java.util.Scanner;

public class FileCopy
{
	public static void main(String[] args)
	{
		if(args.length != 2)
		{
			System.out.println("java FileCopy <�ҽ�����> <��������>");
			
		}
		else
		{
			try
			{
				copy(args[0], args[1]);
			}
			catch(IOException e)
			{
				System.err.println(e.getMessage());
			}
		}
	} // end of main()
	
	private static void abort(String msg) throws IOException
	{
		throw new IOException("FileCopy: " + msg);
	}
	
	public static void copy(String from, String to) throws IOException
	{
		File fromFile = new File(from);
		File toFile = new File(to);
		
		//�ҽ� ���Ͽ� ���� �˻�
		if (!fromFile.exists()) throw new IOException("���� ���� ����: " + from);
		if (!fromFile.isFile()) throw new IOException("���丮 ���� �Ұ�: " + from);
		if (!fromFile.canRead()) throw new IOException("���� �б� �Ұ�: " + from);
		
		//toFile�� ���丮�̸� fromFile�� target file name���� ����Ѵ�.
		if (toFile.isDirectory()) toFile = new File(toFile, fromFile.getName());
		
		//���� ���� �˻�
		if(toFile.exists()) //target file�� �����ϴ� ��� 
		{
			if(!toFile.canWrite()) abort("���� ���� ���� �Ұ�: " + to);
			System.out.println("������? " + to + " (Y/N): ");
			Scanner s = new Scanner(System.in);
			String response = s.next();
			
			if(!response.equals("Y") && !response.equals("y"))
			{
				abort("���� ���� �ʰ� ��Ĩ�ϴ�.");
			}
			else //������ �������� �ʴ� ���
			{
				String parent = toFile.getParent();		//target directory pathname ȹ��
				if (parent == null) parent = System.getProperty("user.dir");
				File dir = new File(parent);
				if(!dir.exists()) abort("���� ���丮�� �������� ����: " + parent);
				if(dir.isFile()) abort("�������� ���丮�� �ƴ�: " + parent);
				if(!dir.canWrite()) abort("���� ���丮 ���� �Ұ�: " + parent);
			}
		}
		
		//����
		FileInputStream in = null;
		FileOutputStream out = null;
		
		try
		{
			in = new FileInputStream(fromFile);
			out = new FileOutputStream(toFile);
			byte[] buffer = new byte[4096];
			int bytesRead;
			
			while((bytesRead = in.read(buffer)) != -1) // while not end of stream
			{
				out.write(buffer, 0, bytesRead);
			}
		}
		finally
		{
			if(in != null) try{in.close();} catch(IOException e){}
			if(out != null) try{out.close();} catch(IOException e){}
		}
	} //copy()
} //FileCopy
