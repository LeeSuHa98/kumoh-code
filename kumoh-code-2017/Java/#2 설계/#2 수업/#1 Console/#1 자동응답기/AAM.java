import java.util.Scanner;

public class AAM
{
	Scanner sc = new Scanner(System.in);
	
	private static final int MAX_COUNT = 10;
	private String message;
	private String[] msg;
	private int count;
	
	public AAM()
	{
		msg = new String[MAX_COUNT];
		count = 0;
	}
	
	public void connect()	// �ʱ� �޽���("���� �Ǿ����ϴ�")�� ȭ�鿡 ����ϰ� ���� ���� ����(����Ǿ��ٰ� ���������� ǥ��)
	{
		System.out.println("���� �Ǿ����ϴ�");
	}
	public void record()	// �Է� �ȳ���("���� �޽��� : ")�� ����ϰ� �޽����� Ű���带 ���� �Է¹���
	{
		System.out.print("���� �޽���: ");

//		if (msg == null)
//		{
//			System.out.println("DisConnected");
//		}
		if (count > MAX_COUNT)
		{
			System.out.println("�޽����� �ִ� 10�� ���� ���� ����");
			System.out.println("DisConnected");
		}
		
		message = sc.next();
		msg[count] = message;
		count++;
	}
	public void play()
	{
		if (msg == null)
		{
			System.out.println("������� �ʴ� �����Դϴ�.");
		}
		else
		{
			System.out.println("���� �޽��� : " + message);
		}
	}
	public void play(int n)
	{
		System.out.println(n+1 + "��° �޽��� : " + msg[n]);
	}
	public int getMsgNum()	// ����Ǿ� �ִ� �޽��� ������ ���� ��
	{
		return count;
	}
	public void movePos(int n)	// n ��° �޽����� �̵�
	{
		for (int i = 0; i < n; i++)
		{
			System.out.println(n + "��° �޽����� �̵� : " + msg[n-1]);
		}
	}
	public void deleteMsg()	// �� ��ġ�� �޽��� ����
	{
		msg = null;
	}
	public void disconnect()	// ���� ����
	{
		System.out.println("Disconnect");
		msg = null;
		count = 0;
	}
}
