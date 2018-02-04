package 자리예약;

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
			System.out.println("------------   영화 예약 시스템            ----------");
			System.out.println("------------   1. 영화 좌석 예약        ----------");
			System.out.println("------------   2. 영화 좌석 예약 취소 ----------");
			System.out.println("------------   3. 영화 좌석 예약 현황 ----------");
			System.out.println("------------   4. 종료                      ----------");
			System.out.print("선택 : ");
			
			int menu = sc.nextInt();
			
			switch(menu)
			{
			case 1:	// 1. 영화 예약
				t.reservationTheater();
				break;
			case 2:	// 2. 영화 예약 취소
				t.cancelTheater();
				break;
			case 3:	// 3. 영화 예약 현황
				t.displayTheater();
				break;
			case 4:	// 4. 종료
				System.exit(1);
			}
		}
	}
}
