import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Bicycle b = new Bicycle();
		
		System.out.println("자전거 탑승");
		b.stateBicycle();
		
		int select;
		while(true)
		{
			System.out.println("자전거를 운행합니다.");
			System.out.println("1. 가속운행");
			System.out.println("2. 감속운행");
			System.out.println("3. 등속운행");
			System.out.print("선택:");
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				b.speedUp(10);
				System.out.println("속도 :" + b.getSpeed() + "km/h");
				break;
			case 2:
				b.speedDown(10);
				System.out.println("속도 :" + b.getSpeed() + "km/h");
				break;
			case 3:
				b.speedEqual(b.getSpeed());
				System.out.println("속도 :" + b.getSpeed() + "km/h");
				break;
			}
			if(b.getSpeed() == 0)
			{
				System.out.println("자전거 하차");
				b.stateBicycle();
				break;
			}
		}
	}
}
