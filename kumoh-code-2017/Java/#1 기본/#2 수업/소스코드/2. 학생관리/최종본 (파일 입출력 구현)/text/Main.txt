package 학생관리;

import java.io.IOException;

//enum Menus {INSERT, DELETE, UPDATE, DISPLAY, EXIT;}

public class Main
{
	public static void main(String args[])
	{
		StudentList s_list = new StudentList();
		TaskManager tm = new TaskManager();
		ioHandler ioh = new ioHandler();
		
		try
		{
			ioh.loadStudent("student.txt", s_list);
		} catch (IOException e1)
		{
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		while(true)
		{
			int menu = ioh.getMenu();
			
			switch(menu)
			{
			case 1:
				// 학생정보 등록
				tm.registerStudent(s_list);
				break;
			case 2:
				// 학생정보 삭제
				tm.unregisterStudent(s_list);
				break;
			case 3:
				// 학생정보 수정
				tm.changeStudent(s_list);
				break;
			case 4:
				// 학생정보 출력
				tm.displayStudent(s_list);
				break;
			case 5:
				try
				{
					ioh.saveStudent("student.txt", s_list);
				} catch (IOException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.exit(1);
			default:
				System.out.println("잘못 입력하셨습니다. ");
			}
		}
	}
}
