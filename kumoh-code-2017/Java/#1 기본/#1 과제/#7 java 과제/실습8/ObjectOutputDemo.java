import java.io.*;
import java.util.Date;

public class ObjectOutputDemo
{
	public static void main(String[] args) throws IOException
	{
		// 1. 스트림 생성
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(args[0]));
		
		// 2. 쓰기 연산 수행
		oos.writeChar('1');
		oos.writeBoolean(true);
		oos.writeDouble(100.0);
		oos.writeUTF("abc");
		
		// (MUST) Serializable 객체만 쓰기 가능.
		oos.writeObject(new Date());
		
		// 3. 스트림 닫기
		oos.close();
	}
}
