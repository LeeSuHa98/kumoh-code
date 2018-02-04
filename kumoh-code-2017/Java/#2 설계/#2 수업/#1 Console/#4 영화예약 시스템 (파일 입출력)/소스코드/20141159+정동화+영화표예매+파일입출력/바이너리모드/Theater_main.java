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
				System.out.println("1.�ҷ�����");
				System.out.println("2.�޴�â");
				System.out.println("3.����");
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
					System.out.println("1~3������ �����Է�");
				}
				if(menu_check == true) {
					while(true) {
						System.out.println("====menu====");
						System.out.println("1.�¼�ǥ����");
						System.out.println("2.�����ϱ�");
						System.out.println("3.�������");
						System.out.println("4.�����ϱ�");
						System.out.println("5.����");
						System.out.println("============");

						choose = sc.nextInt();


						if(choose == 1) {
							t.show_seats();
						}
						else if(choose == 2) {
							System.out.println("������ �ڸ��Է�(��,��):");
							int ro = sc.nextInt();
							int co = sc.nextInt();
							try {
								t.reserve(ro, co);
							}catch(MyException e) {
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
							;
						}
						else if(choose == 4) {
							File f = new File("C:\\Temp\\Theater.out");
							if(f.isFile()) {
								System.out.println("���������� �����մϴ� ���� �����Ͻðڽ��ϱ�? (Y/N)");
								char yn =  sc.next().charAt(0);
								if(yn == 'Y') {
									t.save("C:\\Temp\\Theater.out");
								}
								else if( yn == 'N') {
									System.out.println("�������� ����");
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
							System.out.println("1~5������ ���� �Է�");
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
