import java.io.*;

public class DataOutputDemo
{
	public static void main(String[] args) throws IOException
	{
		// 1. ��Ʈ�� ����
		DataOutputStream dos = new DataOutputStream(new FileOutputStream(args[0]));
		
		// 2. ���� ���� ����
		dos.writeChar('1');
		dos.writeBoolean(true);
		dos.writeLong(100L);
		dos.writeDouble(100.0);
		dos.writeUTF("abc");
		
		// 3. ��Ʈ�� �ݱ�
		dos.close();
	}
}
