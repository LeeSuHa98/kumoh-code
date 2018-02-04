import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class FilePrint
{
	public static void main(String arg[]) throws IOException
	{
		char c;
		
		RandomAccessFile file = new RandomAccessFile(arg[0], "rw");
		while(file.getFilePointer() < file.length())
		{
			System.out.println(file.readLine());
		}
	}
}
