import java.io.*;
import java.util.Date;

public class ObjectInputDemo
{
	public static void main(String[] args) throws IOException, ClassNotFoundException
	{
		// 1. 스트림 생성
		// (MUST) source file은 ObjectOutputStream을 통해 write한 파일.
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream(args[0]));
		
		// 2. 읽기 연산 수행
		System.out.println(ois.readChar());		// (MUST)
		System.out.println(ois.readBoolean());	// write와 동일한
		System.out.println(ois.readDouble());	// 순서로 read.
		System.out.println(ois.readUTF());		//
		
		// 객체 읽기; 타입변환 時 ClassNotFoundException 발생 가능.
		System.out.println((Date)ois.readObject());
		
		// 3. 스트림 닫기
		ois.close();
	}
}

