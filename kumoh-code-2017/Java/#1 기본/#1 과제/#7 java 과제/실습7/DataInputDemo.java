import java.io.*;

public class DataInputDemo
{
	public static void main(String[] args) throws IOException
	{
		// 1. 스트림 생성
		// (MUST) source file은 DataOutputStream을 통해 write한 파일.
		DataInputStream dis = new DataInputStream(new FileInputStream(args[0]));
		
		// 2. 읽기 연산 수행
		System.out.println(dis.readChar());		// (MUST)
		System.out.println(dis.readBoolean());	//
		System.out.println(dis.readLong());		// write와 동일한
		System.out.println(dis.readDouble());	// 순서로 read.
		System.out.println(dis.readUTF());		//
		
		// 3. 스트림 닫기
		dis.close();
	}
}
