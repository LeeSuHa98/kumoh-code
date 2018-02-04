import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		Car c = new Car();
		
		System.out.println("시동걸기");
		c.stateCar();
		
		int select;
		while(true)
		{
			System.out.println("자동차를 운행합니다.");
			System.out.println("1. 가속운행");
			System.out.println("2. 감속운행");
			System.out.println("3. 변속운행");
			System.out.println("4. 연료주입");
			System.out.print("선택:");
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				c.speedUp(10);
				System.out.println("속도 :" + c.getSpeed() + "km/h");
				System.out.println("연료 :" + c.getFuel() + "L");
				break;
			case 2:
				c.speedDown(10);
				System.out.println("속도 :" + c.getSpeed() + "km/h");
				System.out.println("연료 :" + c.getFuel() + "L");
				break;
			case 3:
				c.speedGear();
				System.out.println("속도 :" + c.getSpeed() + "km/h");
				System.out.println("연료 :" + c.getFuel() + "L");
				break;
			case 4:
				c.fuellingCar();
				System.out.println("연료 :" + c.getFuel() + "L");
			}
			if(c.getFuel() <= 0.0)
			{
				System.out.println("경고! 연료가 부족합니다.");
				System.out.println("시동정지");
				System.out.println("연료 : " + c.getFuel() + "L");
				System.out.println("속도 : " + c.getSpeed() + "km/h");
				System.out.println();
				
				System.out.println("연료를 재충전 하시겠습니까?");
				System.out.println("1. 연료 재충전");
				System.out.println("2. 시동정지");
				System.out.print("선택:");
				
				select = sc.nextInt();
				switch(select)
				{
				case 1:
					System.out.println("연료 재충전을 시작합니다.");
					c.fuellingCar();
					System.out.println("연료 : " + c.getFuel() + "L");
					continue;
				case 2:
					System.out.println("연료 재충전을 하지않습니다.");
					System.out.println("시동정지");
					System.out.println("연료 : " + c.getFuel() + "L");
					c.stateCar();
					System.exit(1);
				}
			}
		}
	}
}
