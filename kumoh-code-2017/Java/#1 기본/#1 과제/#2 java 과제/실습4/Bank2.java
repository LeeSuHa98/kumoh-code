import java.util.Scanner;

public class Bank2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		AccountList a_list = new AccountList();
		
		while(true)
		{
			System.out.println("------ Account ���α׷� ------");
			System.out.println("------ 1. ���°���          ------");
			System.out.println("------ 2. �ܰ���ȸ          ------");
			System.out.println("------ 3. �Ա�               ------");
			System.out.println("------ 4. ���               ------");
			System.out.println("------ 5. ���α׷� ����    ------");
			System.out.print("���� : ");
			
			int select;
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				//���°���
				a_list.creatAccount();
				break;
			case 2:
				//�ܰ���ȸ
				a_list.showAccount();
				break;
			case 3:
				//�Ա�
				a_list.depositAccount();
				break;
			case 4:
				//���
				a_list.withdrawAccount();
				break;
			case 5:
				//���α׷� ����
				System.exit(1);
			}
		}
	}
}
