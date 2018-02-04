import java.util.Scanner;

public class Car
{
	Scanner sc = new Scanner(System.in);

	private double fuel; // ����
	private int speed; // �ӵ�
	private boolean state; // ����

	public Car()
	{
		fuel = 0.0;
		speed = 0;
		state = false;
	}
	public int getSpeed(){return speed;}
	public double getFuel(){return fuel;}

	public void stateCar()
	{
		if(state == true)
		{
			state = false;
		}
		else
		{
			state = true;
		}
	}
	public void speedUp(int index) // ���ӿ���
	{
		if(state == true)
		{
			speed += index;
			fuel -= 1;
		}
	}
	public void speedDown(int index) // ���ӿ���
	{
		if(state == true)
		{
			if(speed <= 0)
			{
				speed = 0;
			}
			else if(speed > 0)
			{
				speed -= index;
				fuel -= 1;
			}
		}
	}
	public void speedGear() // ���ӿ���
	{
		if(state == true)
		{
			System.out.println("�ڵ����� �����մϴ�.");
			System.out.println("1. 1��(D1) Gear");
			System.out.println("2. 2��(D2) Gear");
			System.out.println("3. 3��(D3) Gear");
			System.out.println("4. ����(P) Gear");
			System.out.println("5. ����(R) Gear");
			System.out.print("���� :");

			int gear = sc.nextInt();

			if(state == true)
			{
				switch(gear)
				{
				case 1:
					speed += 10;
					fuel -= 1;
					break;
				case 2:
					speed += 20;
					fuel -= 2;
					break;
				case 3:
					speed += 30;
					fuel -= 3;
					break;
				case 4:
					speed = 0;
					break;
				case 5:
					if(speed <= 0)
					{
						speed = 0;
						fuel -= 1;
					}
					else if(speed > 0)
					{
						speed -= 10;
						fuel -= 1;
					}
					break;
				}
			}
		}
	}
	public void fuellingCar() // ��������
	{
		System.out.println("���Ḧ �����մϴ�.");
		System.out.println("1. 10L ����");
		System.out.println("2. 20L ����");
		System.out.println("3. 30L ����");
		System.out.print("���� :");

		int select = sc.nextInt();

		if(state == true)
		{
			switch(select)
			{
			case 1:
				fuel += 10.0;
				break;
			case 2:
				fuel += 20.0;
				break;
			case 3:
				fuel += 30.0;
				break;
			}
		}
	}
}
