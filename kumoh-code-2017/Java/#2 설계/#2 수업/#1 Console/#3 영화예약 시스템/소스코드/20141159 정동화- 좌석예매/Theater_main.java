

import java.util.*;
public class Theater_main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("�¼��� ũ���Է�(��,��): ");
		int row = sc.nextInt();
		int col = sc.nextInt();
		Theater t = new Theater(row,col);
		int choose;
		while(true) {
			System.out.println("====menu====");
			System.out.println("1.������Ȳ");
			System.out.println("2.�����ϱ�");
			System.out.println("3.�������");
			System.out.println("4.����");
			System.out.println("============");

			choose = sc.nextInt();
			if(choose == 1) {
				t.show_seats(row, col);
			}
			else if(choose == 2) {
				System.out.println("������ �ڸ��Է�(��,��):");
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
				System.out.println("��������� �ڸ��Է�(��,��):");
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
				System.out.println("1~4������ ���� �Է�");
			}

		}
		sc.close();
	}

}
