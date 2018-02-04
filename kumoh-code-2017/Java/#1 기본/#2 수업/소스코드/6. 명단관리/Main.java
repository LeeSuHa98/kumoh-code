package 명단관리;

import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		MemberList m_list = new MemberList();
		ioHandler ioh = new ioHandler();
		TaskManager tm = new TaskManager();
		
		
		while(true)
		{
			int menu = ioh.getMenu();
			
			switch(menu)
			{
			case 1:
				//명단정보 등록
				tm.registerMember(m_list);
				break;
			case 2:
				//명단정보 삭제
				tm.unregisterMember(m_list);
				break;
			case 3:
				//명단정보 수정
				tm.changeMember(m_list);
				break;
			case 4:
				//명단정보 출력
				tm.displayMember(m_list);
				break;
			case 5:
				//프로그램 종료
				System.exit(1);
			}
		}
	}
}