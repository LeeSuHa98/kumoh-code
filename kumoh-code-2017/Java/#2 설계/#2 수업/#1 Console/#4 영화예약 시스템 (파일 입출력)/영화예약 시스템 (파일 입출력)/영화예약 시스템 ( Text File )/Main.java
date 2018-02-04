package 자리예약;

import java.util.Scanner;
import java.io.IOException;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Theater t = new Theater();

		boolean menuCheck = true;

		while(true)
		{
			if(menuCheck == true)
			{
				System.out.println("------------   영화 좌석 예약 시스템           ----------");
				System.out.println("------------   1. 예약 메뉴                     ----------");
				System.out.println("------------   2. 좌석 기록 불러오기        ----------");
				System.out.println("------------   3. 좌석 기록 저장하기        ----------");
				System.out.println("------------   4. 영화 좌석 예약 현황       ----------");
				System.out.println("------------   5. 종료                            ----------");
				System.out.print("선택 : ");

				int menu = sc.nextInt();

				switch(menu)
				{
				case 1:
					menuCheck = false;
					break;
				case 2:
					try
					{
						t.loadTheater("movie.txt");
					}
					catch(IOException e)
					{
						e.printStackTrace();
					}
					break;
				case 3:
					try
					{
						t.saveTheater("movie.txt");
					} catch (IOException e)
					{
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					break;
				case 4:
					t.displayTheater();
					break;
				case 5:
					System.exit(1);
				}	
			}
			else if(menuCheck == false)
			{
				while(menuCheck == false)
				{
					System.out.println("------------   예약 메뉴                      ----------");
					System.out.println("------------   1. 영화 좌석 예약        ----------");
					System.out.println("------------   2. 영화 좌석 예약 취소 ----------");
					System.out.println("------------   3. 영화 좌석 예약 현황 ----------");
					System.out.println("------------   4. 메뉴 돌아가기         ----------");
					System.out.println("------------   5. 종료                      ----------");
					System.out.print("선택 : ");

					int subMenu = sc.nextInt();

					switch(subMenu)
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
					case 4:
						menuCheck = true;
						break;
					case 5:	// 4. 종료
						System.exit(1);
					}
				}
			}
		}
	}
}
