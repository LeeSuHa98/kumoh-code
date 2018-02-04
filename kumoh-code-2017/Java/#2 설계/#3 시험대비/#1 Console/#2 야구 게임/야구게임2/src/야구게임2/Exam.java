package 야구게임2;

import java.util.Scanner;

public class Exam {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int num = (int) (Math.random() * 1000) + 1;
		System.out.println("생성된 숫자 : " + num);

		int temp = num / 10;
		int three = temp / 10;
		int two = temp % 10;
		int one = num % 10;

		int[] su = new int[3];

		su[0] = one;
		su[1] = two;
		su[2] = three;

		int count = 1;

		System.out.println("야구게임 시작");

		while (true) {

			System.out.println("숫자를 입력하세요 : ");
			int input = sc.nextInt();
			int tp = input / 10;
			int sthree = tp / 10;
			int stwo = tp % 10;
			int sone = input % 10;  

			int[] su2 = new int[3];
			su2[0] = sone;
			su2[1] = stwo;
			su2[2] = sthree;

			int scount = 0;

			for (int i = 0; i < 3; i++) {
				if (su[i] == su2[i]) {
					scount++;
				}
			}
			System.out.print(scount + "s ");

			int bcount = 0;
			if (su[0] == su2[1])
				bcount++;
			if (su[0] == su2[2])
				bcount++;
			if (su[1] == su2[0])
				bcount++;
			if (su[1] == su2[2])
				bcount++;
			if (su[2] == su2[0])
				bcount++;
			if (su[2] == su2[1])
				bcount++;
			System.out.print(bcount + "b ");

			if (scount == 0 && bcount == 0)
				System.out.print("out");   

			if(scount == 3)
				break;

			count++;
		}
		System.out.print(count + "번째 성공"); 
	}
}
