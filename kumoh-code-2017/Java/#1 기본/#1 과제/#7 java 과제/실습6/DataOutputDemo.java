import java.io.*;

public class DataOutputDemo
{
	public static void main(String[] args) throws IOException
	{
		// 1. 스트림 생성
		DataOutputStream dos = new DataOutputStream(new FileOutputStream(args[0]));
		
		// 2. 쓰기 연산 수행
		dos.writeChar('1');
		dos.writeBoolean(true);
		dos.writeLong(100L);
		dos.writeDouble(100.0);
		dos.writeUTF("abc");
		
		// 3. 스트림 닫기
		dos.close();
	}
}
