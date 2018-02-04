package �ڸ�����;

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
				System.out.println("------------   ��ȭ �¼� ���� �ý���           ----------");
				System.out.println("------------   1. ���� �޴�                     ----------");
				System.out.println("------------   2. �¼� ��� �ҷ�����        ----------");
				System.out.println("------------   3. �¼� ��� �����ϱ�        ----------");
				System.out.println("------------   4. ��ȭ �¼� ���� ��Ȳ       ----------");
				System.out.println("------------   5. ����                            ----------");
				System.out.print("���� : ");

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
					System.out.println("------------   ���� �޴�                      ----------");
					System.out.println("------------   1. ��ȭ �¼� ����        ----------");
					System.out.println("------------   2. ��ȭ �¼� ���� ��� ----------");
					System.out.println("------------   3. ��ȭ �¼� ���� ��Ȳ ----------");
					System.out.println("------------   4. �޴� ���ư���         ----------");
					System.out.println("------------   5. ����                      ----------");
					System.out.print("���� : ");

					int subMenu = sc.nextInt();

					switch(subMenu)
					{
					case 1:	// 1. ��ȭ ����
						t.reservationTheater();
						break;
					case 2:	// 2. ��ȭ ���� ���
						t.cancelTheater();
						break;
					case 3:	// 3. ��ȭ ���� ��Ȳ
						t.displayTheater();
						break;
					case 4:
						menuCheck = true;
						break;
					case 5:	// 4. ����
						System.exit(1);
					}
				}
			}
		}
	}
}
