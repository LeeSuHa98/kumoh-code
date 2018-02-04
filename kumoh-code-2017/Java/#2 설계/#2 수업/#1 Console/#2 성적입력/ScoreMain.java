import java.util.Scanner;

public class ScoreMain
{	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		ScoreList s_list = new ScoreList();
		
		while(true)
		{
			System.out.println("------ 성적관리 프로그램 ------");
			System.out.println("------ 1. 성적입력          ------");
			System.out.println("------ 2. 성적출력          ------");
			System.out.println("------ 3. 프로그램 종료    ------");
			System.out.print("선택 : ");
			
			int select;
			select = sc.nextInt();
			
			switch(select)
			{
			case 1:
				//계좌개설
				s_list.registerScore();
				break;
			case 2:
				//잔고조회
				s_list.displayScore();
				break;

			case 3:
				//프로그램 종료
				System.exit(1);
			}
		}
	}
}
