package �ڸ�����;

import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Seat s = new Seat();
		Theater t = new Theater();
		
		while(true)
		{
			System.out.println("------------   ��ȭ ���� �ý���            ----------");
			System.out.println("------------   1. ��ȭ �¼� ����        ----------");
			System.out.println("------------   2. ��ȭ �¼� ���� ��� ----------");
			System.out.println("------------   3. ��ȭ �¼� ���� ��Ȳ ----------");
			System.out.println("------------   4. ����                      ----------");
			System.out.print("���� : ");
			
			int menu = sc.nextInt();
			
			switch(menu)
			{
			case 1:	// 1. ��ȭ ����
				t.reservationTheater();
				break;
			case 2:	// 2. ��ȭ ���� ���
				t.cancelTheater();
				break;
			case 3:	// 3. ��ȭ ���� ��Ȳ
				t.displayTheater();
				break;
			case 4:	// 4. ����
				System.exit(1);
			}
		}
	}
}
