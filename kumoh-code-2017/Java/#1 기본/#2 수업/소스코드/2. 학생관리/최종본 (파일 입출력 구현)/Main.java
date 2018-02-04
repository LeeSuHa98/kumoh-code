package �л�����;

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
				// �л����� ���
				tm.registerStudent(s_list);
				break;
			case 2:
				// �л����� ����
				tm.unregisterStudent(s_list);
				break;
			case 3:
				// �л����� ����
				tm.changeStudent(s_list);
				break;
			case 4:
				// �л����� ���
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
				System.out.println("�߸� �Է��ϼ̽��ϴ�. ");
			}
		}
	}
}
