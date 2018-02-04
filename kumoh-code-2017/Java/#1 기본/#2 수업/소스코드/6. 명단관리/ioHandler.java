package ��ܰ���;

import java.util.Scanner;

public class ioHandler
{
	Scanner sc = new Scanner(System.in);
	
	public int getMenu()
	{
		System.out.println("------ ��ܰ��� ���α׷� ------");
		System.out.println("------ 1. ��� ���� ��� ------");
		System.out.println("------ 2. ��� ���� ���� ------");
		System.out.println("------ 3. ��� ���� ���� ------");
		System.out.println("------ 4. ��� ���� ��� ------");
		System.out.println("------ 5. ���α׷� ����  ------");

		int menu = getInteger(" ���� : ");

		if (menu >= 1 && menu <= 5)
		{
			return menu;
		}
		return 0;
	}

	public int getInteger(String msg)
	{
		int value;
		
		System.out.print(msg);
		value = sc.nextInt();

		return value;
	}

	public String getString(String msg)
	{
		String value;

		System.out.print(msg);
		value = sc.next();

		return value;
	}

	public Faculty insertFaculty()
	{
		// ID
		String id = getString(" ID : ");
		// ����
		String name = getString(" ���� : ");
		// �Ҽ��а�
		String department = getString(" �Ҽ��а� : ");
		// �����о�
		int major = getInteger(" �����о� : ");
		// ��������
		String degree = getString(" �������� : ");

		Faculty f = new Faculty(id, name, department, major, degree);

		return f;
	}

	public Staff insertStaff()
	{
		// ID
		String id = getString(" ID : ");
		// ����
		String name = getString(" ���� : ");
		// �ҼӺμ�
		String department = getString(" �ҼӺμ� : ");
		// ����
		int rank = getInteger(" ����: ");
		// ������
		String duty = getString(" ������ : ");

		Staff s = new Staff(id, name, department, rank, duty);

		return s;
	}

	public Undergraduate insertUndergraduate()
	{
		// ID
		String id = getString(" ID : ");
		// ����
		String name = getString(" ���� : ");
		// �Ҽ��а�
		String department = getString(" �Ҽ��а� : ");
		// �г�
		int grade = getInteger(" �г� : ");
		// ��������
		String advisor = getString(" �������� : ");

		Undergraduate u = new Undergraduate(id, name, department, grade, advisor);

		return u;
	}

	public Graduate insertGraduate()
	{
		// ID
		String id = getString(" ID : ");
		// ����
		String name = getString(" ���� : ");
		// �Ҽ��а�
		String department = getString(" �Ҽ��а� : ");
		// ��������
		String degree = getString(" �������� : ");
		// �����о�
		int major = getInteger(" �����о� : ");
		// ��������
		String advisor = getString(" �������� : ");

		Graduate g = new Graduate(id, name, department, degree, major, advisor);

		return g;
	}

	public Member getMember(char member_type)
	{
		if (member_type == 'F')
		{
			// Faculty
			Member mp = insertFaculty();

			return mp;
		}
		else if (member_type == 'S')
		{
			// Staff
			Member mp = insertStaff();

			return mp;
		}
		else if (member_type == 'U')
		{
			// Undergraduate
			Member mp = insertUndergraduate();

			return mp;
		}
		else if (member_type == 'G')
		{
			// Graduate
			Member mp = insertGraduate();

			return mp;
		}
		return null;
	}

	public char insertMemberType()
	{
		char member_type;

		while (true)
		{
			System.out.println();
			System.out.println("(F:����, S:����, U:�кλ�, G:���п���) -> ");
			member_type = sc.next().charAt(0);

			if (member_type == 'F' || member_type == 'S' || member_type == 'U' || member_type == 'G')
			{
				return member_type;
			}
			else
			{
				System.out.println("�߸� �Է��ϼ̽��ϴ�.");
			}
		}
	}
}
