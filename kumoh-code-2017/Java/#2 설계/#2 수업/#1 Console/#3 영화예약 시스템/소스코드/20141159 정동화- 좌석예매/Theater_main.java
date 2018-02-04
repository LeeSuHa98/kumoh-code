

import java.util.*;
public class Theater_main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("좌석의 크기입력(행,열): ");
		int row = sc.nextInt();
		int col = sc.nextInt();
		Theater t = new Theater(row,col);
		int choose;
		while(true) {
			System.out.println("====menu====");
			System.out.println("1.예약현황");
			System.out.println("2.예약하기");
			System.out.println("3.예약취소");
			System.out.println("4.종료");
			System.out.println("============");

			choose = sc.nextInt();
			if(choose == 1) {
				t.show_seats(row, col);
			}
			else if(choose == 2) {
				System.out.println("예약할 자리입력(행,열):");
				int ro = sc.nextInt();
				int co = sc.nextInt();
				try {
				t.reserve(ro, co);
				}
				catch(MyException e) {
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
			}
			else if(choose == 4) {
				break;
			}
			else {
				System.out.println("1~4사이의 숫자 입력");
			}

		}
		sc.close();
	}

}
