package ��ܰ���;

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
				//������� ���
				tm.registerMember(m_list);
				break;
			case 2:
				//������� ����
				tm.unregisterMember(m_list);
				break;
			case 3:
				//������� ����
				tm.changeMember(m_list);
				break;
			case 4:
				//������� ���
				tm.displayMember(m_list);
				break;
			case 5:
				//���α׷� ����
				System.exit(1);
			}
		}
	}
}