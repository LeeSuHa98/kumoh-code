public class Main
{
	public static void main(String[] args)
	{
		AAM machine1 = new AAM();
		machine1.connect();
		machine1.record();
		machine1.play();
		machine1.record();
		machine1.record();

		int c = machine1.getMsgNum();
		for (int i = 0; i < c; i++) machine1.play(i);
		machine1.movePos(1);
		machine1.deleteMsg();
		
		System.out.println("�� �޽����� ������ " + machine1.getMsgNum() + "�Դϴ�.");
		machine1.disconnect();
		machine1.play(); // "������� �ʴ� �����Դϴ�."��� �޽��� ���
		machine1.connect();

		System.out.println("�� �޽����� ������ " + machine1.getMsgNum() + "�Դϴ�.");
		machine1.disconnect();
	}
}