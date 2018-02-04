import java.io.*;
import java.util.Date;

public class ObjectOutputDemo
{
	public static void main(String[] args) throws IOException
	{
		// 1. ��Ʈ�� ����
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(args[0]));
		
		// 2. ���� ���� ����
		oos.writeChar('1');
		oos.writeBoolean(true);
		oos.writeDouble(100.0);
		oos.writeUTF("abc");
		
		// (MUST) Serializable ��ü�� ���� ����.
		oos.writeObject(new Date());
		
		// 3. ��Ʈ�� �ݱ�
		oos.close();
	}
}
