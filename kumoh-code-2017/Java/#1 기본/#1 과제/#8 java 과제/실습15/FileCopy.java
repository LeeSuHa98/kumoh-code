import java.io.*;
import java.util.Scanner;

public class FileCopy
{
	public static void main(String[] args)
	{
		if(args.length != 2)
		{
			System.out.println("java FileCopy <소스파일> <목적파일>");
			
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
		
		//소스 파일에 대한 검사
		if (!fromFile.exists()) throw new IOException("파일 존재 않음: " + from);
		if (!fromFile.isFile()) throw new IOException("디렉토리 복사 불가: " + from);
		if (!fromFile.canRead()) throw new IOException("파일 읽기 불가: " + from);
		
		//toFile이 디렉토리이면 fromFile을 target file name으로 사용한다.
		if (toFile.isDirectory()) toFile = new File(toFile, fromFile.getName());
		
		//목적 파일 검사
		if(toFile.exists()) //target file이 존재하는 경우 
		{
			if(!toFile.canWrite()) abort("목적 파일 쓰기 불가: " + to);
			System.out.println("덮어쓸까요? " + to + " (Y/N): ");
			Scanner s = new Scanner(System.in);
			String response = s.next();
			
			if(!response.equals("Y") && !response.equals("y"))
			{
				abort("덮어 쓰지 않고 마칩니다.");
			}
			else //파일이 존재하지 않는 경우
			{
				String parent = toFile.getParent();		//target directory pathname 획득
				if (parent == null) parent = System.getProperty("user.dir");
				File dir = new File(parent);
				if(!dir.exists()) abort("목적 디렉토리가 존재하지 않음: " + parent);
				if(dir.isFile()) abort("목적지가 디렉토리가 아님: " + parent);
				if(!dir.canWrite()) abort("목적 디렉토리 쓰기 불가: " + parent);
			}
		}
		
		//복사
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
