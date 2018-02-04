import java.util.Scanner;

public class Car
{
	Scanner sc = new Scanner(System.in);

	private double fuel; // 연료
	private int speed; // 속도
	private boolean state; // 상태

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
	public void speedUp(int index) // 가속운행
	{
		if(state == true)
		{
			speed += index;
			fuel -= 1;
		}
	}
	public void speedDown(int index) // 감속운행
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
	public void speedGear() // 변속운행
	{
		if(state == true)
		{
			System.out.println("자동차를 변속합니다.");
			System.out.println("1. 1단(D1) Gear");
			System.out.println("2. 2단(D2) Gear");
			System.out.println("3. 3단(D3) Gear");
			System.out.println("4. 정지(P) Gear");
			System.out.println("5. 후진(R) Gear");
			System.out.print("선택 :");

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
	public void fuellingCar() // 연료주입
	{
		System.out.println("연료를 주입합니다.");
		System.out.println("1. 10L 주입");
		System.out.println("2. 20L 주입");
		System.out.println("3. 30L 주입");
		System.out.print("선택 :");

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
