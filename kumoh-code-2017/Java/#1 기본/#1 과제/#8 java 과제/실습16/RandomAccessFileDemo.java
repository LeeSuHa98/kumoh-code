import java.io.IOException;
import java.io.RandomAccessFile;

public class RandomAccessFileDemo
{
	public static void main(String[] args)throws IOException
	{
		try(RandomAccessFile inout = new RandomAccessFile("inout.dat", "rw"))
		{
			// ���Ͽ� �����ϴ� ���� ����
			inout.setLength(0);
			
			for (int i = 0; i < 200; i++)
			{
				inout.writeInt(i);
			}
			System.out.println("���� ���� ����" + inout.length());
			
			// ù��° �� �˻�
			inout.seek(0); System.out.println("1st: " + inout.readInt());
			
			// �ټ� ��° �� �˻�; int�� 4bytes.
			inout.seek((5-1) * 4);
			System.out.println("5th: " + inout.readInt());
			
			// �ϰ� ��° �� ����
			inout.seek((7-1) * 4); inout.writeInt(666);
			
			// ���� ���� ���ο� �� �߰�
			inout.seek(inout.length()); inout.writeInt(1111);
		} // end of try
	}
}
