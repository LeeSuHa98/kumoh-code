import java.io.*;
import java.util.Date;

public class ObjectInputDemo
{
	public static void main(String[] args) throws IOException, ClassNotFoundException
	{
		// 1. ��Ʈ�� ����
		// (MUST) source file�� ObjectOutputStream�� ���� write�� ����.
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream(args[0]));
		
		// 2. �б� ���� ����
		System.out.println(ois.readChar());		// (MUST)
		System.out.println(ois.readBoolean());	// write�� ������
		System.out.println(ois.readDouble());	// ������ read.
		System.out.println(ois.readUTF());		//
		
		// ��ü �б�; Ÿ�Ժ�ȯ �� ClassNotFoundException �߻� ����.
		System.out.println((Date)ois.readObject());
		
		// 3. ��Ʈ�� �ݱ�
		ois.close();
	}
}

