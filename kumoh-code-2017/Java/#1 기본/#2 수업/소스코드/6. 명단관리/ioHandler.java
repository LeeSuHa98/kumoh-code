package 명단관리;

import java.util.Scanner;

public class ioHandler
{
	Scanner sc = new Scanner(System.in);
	
	public int getMenu()
	{
		System.out.println("------ 명단관리 프로그램 ------");
		System.out.println("------ 1. 명단 정보 등록 ------");
		System.out.println("------ 2. 명단 정보 삭제 ------");
		System.out.println("------ 3. 명단 정보 수정 ------");
		System.out.println("------ 4. 명단 정보 출력 ------");
		System.out.println("------ 5. 프로그램 종료  ------");

		int menu = getInteger(" 선택 : ");

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
		// 성명
		String name = getString(" 성명 : ");
		// 소속학과
		String department = getString(" 소속학과 : ");
		// 전공분야
		int major = getInteger(" 전공분야 : ");
		// 최종학위
		String degree = getString(" 최종학위 : ");

		Faculty f = new Faculty(id, name, department, major, degree);

		return f;
	}

	public Staff insertStaff()
	{
		// ID
		String id = getString(" ID : ");
		// 성명
		String name = getString(" 성명 : ");
		// 소속부서
		String department = getString(" 소속부서 : ");
		// 직급
		int rank = getInteger(" 직급: ");
		// 담당업무
		String duty = getString(" 담당업무 : ");

		Staff s = new Staff(id, name, department, rank, duty);

		return s;
	}

	public Undergraduate insertUndergraduate()
	{
		// ID
		String id = getString(" ID : ");
		// 성명
		String name = getString(" 성명 : ");
		// 소속학과
		String department = getString(" 소속학과 : ");
		// 학년
		int grade = getInteger(" 학년 : ");
		// 지도교수
		String advisor = getString(" 지도교수 : ");

		Undergraduate u = new Undergraduate(id, name, department, grade, advisor);

		return u;
	}

	public Graduate insertGraduate()
	{
		// ID
		String id = getString(" ID : ");
		// 성명
		String name = getString(" 성명 : ");
		// 소속학과
		String department = getString(" 소속학과 : ");
		// 학위과정
		String degree = getString(" 학위과정 : ");
		// 전공분야
		int major = getInteger(" 전공분야 : ");
		// 지도교수
		String advisor = getString(" 지도교수 : ");

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
			System.out.println("(F:교수, S:직원, U:학부생, G:대학원생) -> ");
			member_type = sc.next().charAt(0);

			if (member_type == 'F' || member_type == 'S' || member_type == 'U' || member_type == 'G')
			{
				return member_type;
			}
			else
			{
				System.out.println("잘못 입력하셨습니다.");
			}
		}
	}
}
