dimport java.io.*;
import java.util.Date;
import java.io.IOException;

public class ObjectIO
{
	public static void main(String[] args) throws IOException
	{
		try
		{
			ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("time.txt"));
			ObjectInputStream in = new ObjectInputStream(new FileInputStream("time.txt"));
			
			out.writeInt(Integer.parseInt(args[0]));
			out.writeObject(args[1]);
			out.writeObject(new Date());
			out.flush();
			out.close();
			
			System.out.println(in.readInt());
			System.out.println((String)in.readObject());
			System.out.println((Date)in.readObject());
			in.close();
		} 
		catch (Exception e)
		{
			System.out.println("사용법 : java ObjectIO 정수 문자열");
		}
	}
}