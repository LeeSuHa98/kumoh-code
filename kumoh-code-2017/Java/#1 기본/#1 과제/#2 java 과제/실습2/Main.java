import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Bicycle b = new Bicycle();
		
		System.out.println("������ ž��");
		b.stateBicycle();
		
		int select;
		while(true)
		{
			System.out.println("�����Ÿ� �����մϴ�.");
			System.out.println("1. ���ӿ���");
			System.out.println("2. ���ӿ���");
			System.out.println("3. ��ӿ���");
			System.out.print("����:");
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				b.speedUp(10);
				System.out.println("�ӵ� :" + b.getSpeed() + "km/h");
				break;
			case 2:
				b.speedDown(10);
				System.out.println("�ӵ� :" + b.getSpeed() + "km/h");
				break;
			case 3:
				b.speedEqual(b.getSpeed());
				System.out.println("�ӵ� :" + b.getSpeed() + "km/h");
				break;
			}
			if(b.getSpeed() == 0)
			{
				System.out.println("������ ����");
				b.stateBicycle();
				break;
			}
		}
	}
}
