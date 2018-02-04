package practice;

import java.io.File;
import java.io.IOException;

import java.util.*;
public class Theater_main {

	public static void main(String[] args) throws IOException, MyException {

		try {
			Scanner sc = new Scanner(System.in);
			Theater t = new Theater();
			int choose;

			int check_load;
			boolean menu_check = false;
			while(true) {
				System.out.println("1.불러오기");
				System.out.println("2.메뉴창");
				System.out.println("3.종료");
				check_load = sc.nextInt();
				if(check_load == 1) {
					t.load("C:\\Temp\\Theater.out");
				}
				else if(check_load ==2 ) {
					menu_check = true;
				}
				else if(check_load == 3) {
					break;
				}
				else {
					System.out.println("1~3사이의 숫자입력");
				}
				if(menu_check == true) {
					while(true) {
						System.out.println("====menu====");
						System.out.println("1.좌석표보기");
						System.out.println("2.예약하기");
						System.out.println("3.예약취소");
						System.out.println("4.저장하기");
						System.out.println("5.종료");
						System.out.println("============");

						choose = sc.nextInt();


						if(choose == 1) {
							t.show_seats();
						}
						else if(choose == 2) {
							System.out.println("예약할 자리입력(행,열):");
							int ro = sc.nextInt();
							int co = sc.nextInt();
							try {
								t.reserve(ro, co);
							}catch(MyException e) {
								e.message();
							}
						}
						else if(choose == 3) {

							System.out.println("예약취소할 자리입력(행,열):");
							int ro = sc.nextInt();
							int co = sc.nextInt();
							try {
								t.reserve_cancel(ro, co);

							}catch(MyException e) {
								e.message();
							}
							;
						}
						else if(choose == 4) {
							File f = new File("C:\\Temp\\Theater.out");
							if(f.isFile()) {
								System.out.println("기존파일이 존재합니다 새로 저장하시겠습니까? (Y/N)");
								char yn =  sc.next().charAt(0);
								if(yn == 'Y') {
									t.save("C:\\Temp\\Theater.out");
								}
								else if( yn == 'N') {
									System.out.println("기존파일 유지");
								}
							}
							else {
								t.save("C:\\Temp\\Theater.out");
							}
						}
						else if(choose == 5)
						{
							break;
						}
						else {
							System.out.println("1~5사이의 숫자 입력");
						}
					}
				}
			}

			sc.close();
		}catch(IOException e) {
			e.printStackTrace();
		}




	}
}
