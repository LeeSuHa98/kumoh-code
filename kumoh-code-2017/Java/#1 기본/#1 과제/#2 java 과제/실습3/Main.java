import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		Car c = new Car();
		
		System.out.println("�õ��ɱ�");
		c.stateCar();
		
		int select;
		while(true)
		{
			System.out.println("�ڵ����� �����մϴ�.");
			System.out.println("1. ���ӿ���");
			System.out.println("2. ���ӿ���");
			System.out.println("3. ���ӿ���");
			System.out.println("4. ��������");
			System.out.print("����:");
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				c.speedUp(10);
				System.out.println("�ӵ� :" + c.getSpeed() + "km/h");
				System.out.println("���� :" + c.getFuel() + "L");
				break;
			case 2:
				c.speedDown(10);
				System.out.println("�ӵ� :" + c.getSpeed() + "km/h");
				System.out.println("���� :" + c.getFuel() + "L");
				break;
			case 3:
				c.speedGear();
				System.out.println("�ӵ� :" + c.getSpeed() + "km/h");
				System.out.println("���� :" + c.getFuel() + "L");
				break;
			case 4:
				c.fuellingCar();
				System.out.println("���� :" + c.getFuel() + "L");
			}
			if(c.getFuel() <= 0.0)
			{
				System.out.println("���! ���ᰡ �����մϴ�.");
				System.out.println("�õ�����");
				System.out.println("���� : " + c.getFuel() + "L");
				System.out.println("�ӵ� : " + c.getSpeed() + "km/h");
				System.out.println();
				
				System.out.println("���Ḧ ������ �Ͻðڽ��ϱ�?");
				System.out.println("1. ���� ������");
				System.out.println("2. �õ�����");
				System.out.print("����:");
				
				select = sc.nextInt();
				switch(select)
				{
				case 1:
					System.out.println("���� �������� �����մϴ�.");
					c.fuellingCar();
					System.out.println("���� : " + c.getFuel() + "L");
					continue;
				case 2:
					System.out.println("���� �������� �����ʽ��ϴ�.");
					System.out.println("�õ�����");
					System.out.println("���� : " + c.getFuel() + "L");
					c.stateCar();
					System.exit(1);
				}
			}
		}
	}
}
