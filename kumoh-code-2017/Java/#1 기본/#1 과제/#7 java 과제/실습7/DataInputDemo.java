import java.io.*;

public class DataInputDemo
{
	public static void main(String[] args) throws IOException
	{
		// 1. ��Ʈ�� ����
		// (MUST) source file�� DataOutputStream�� ���� write�� ����.
		DataInputStream dis = new DataInputStream(new FileInputStream(args[0]));
		
		// 2. �б� ���� ����
		System.out.println(dis.readChar());		// (MUST)
		System.out.println(dis.readBoolean());	//
		System.out.println(dis.readLong());		// write�� ������
		System.out.println(dis.readDouble());	// ������ read.
		System.out.println(dis.readUTF());		//
		
		// 3. ��Ʈ�� �ݱ�
		dis.close();
	}
}
