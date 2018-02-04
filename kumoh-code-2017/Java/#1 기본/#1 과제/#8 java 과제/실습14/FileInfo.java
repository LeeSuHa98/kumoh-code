import java.io.*;
import java.util.*;

public class FileInfo
{
	public static void main(String[] args) throws IOException
	{
		File f = new File(args[0]);
		
		if(f.exists()) // file 존재 검사 (부질의)
		{
			if(f.isFile()) // file 정보 출력
			{
				System.out.println("parent: " + f.getParent());
				System.out.println("name: " + f.getName());
				System.out.println("path: " + f.getPath());
				System.out.println("absolute path: " + f.getAbsolutePath());
				System.out.println("canonical path: " + f.getCanonicalPath());
				System.out.println("size(in bytes): " + f.length());
				System.out.println("last modified time" + new Date(f.lastModified()));
			}
			else // directory listing
			{
				String[] names = f.list();
				for(String x : names)
				{
					System.out.println(x);
				}
			}
		}
	}
}
