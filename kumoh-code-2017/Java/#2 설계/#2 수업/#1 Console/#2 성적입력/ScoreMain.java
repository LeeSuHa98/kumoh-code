import java.util.Scanner;

public class ScoreMain
{	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		ScoreList s_list = new ScoreList();
		
		while(true)
		{
			System.out.println("------ �������� ���α׷� ------");
			System.out.println("------ 1. �����Է�          ------");
			System.out.println("------ 2. �������          ------");
			System.out.println("------ 3. ���α׷� ����    ------");
			System.out.print("���� : ");
			
			int select;
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				//���°���
				s_list.registerScore();
				break;
			case 2:
				//�ܰ���ȸ
				s_list.displayScore();
				break;

			case 3:
				//���α׷� ����
				System.exit(1);
			}
		}
	}
}
