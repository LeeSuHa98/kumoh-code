package 학생관리;

import java.util.Scanner;

public class TaskManager
{	
	Scanner sc = new Scanner(System.in);
	
	ioHandler ioh = new ioHandler();
	
	int findStudent(StudentList s_list, int id) // 학생정보 검색
	{
		for(int i = 0; i < s_list.getCount(); i++)
		{
			if(id == s_list.getStudentList(i).getId())
			{
				return i;
			}
		}
		return 0;
	}
	void registerStudent(StudentList s_list) // 학생정보 등록
	{
		System.out.println("학생 정보를 등록합니다.");
		
		Student s = ioh.getStudent();
		
		s_list.insertStudent(s);
	}
	
	void unregisterStudent(StudentList s_list) // 학생정보 삭제
	{
		System.out.println("학생 정보를 삭제합니다.");
		
		int id = ioh.getInteger("삭제할 학생의 학번을 입력하시오 : ");
		
		for(int i = findStudent(s_list, id); i < s_list.getCount(); i++)
		{
			s_list.deleteStudent(i);
		}
	}
	
	void changeStudent(StudentList s_list)
	{
		System.out.println("학생 정보를 수정합니다.");
		
		System.out.println("수정할 학생의 학번을 입력하시오 :");
		int id = sc.nextInt();
		
		System.out.println("학번 : " + id + " 학생의 정보를 수정합니다.");
		
		
		Student s = ioh.getStudent();
		s_list.updateStudent(findStudent(s_list, id), s);
	}
	
	public void displayStudent(StudentList s_list) // 학생정보 출력
	{
		System.out.println("학생 정보를 출력합니다.");
		
		for(int i = 0; i < s_list.getCount(); i++)
		{
			Student s = s_list.getStudentList(i);
			ioh.putStudent(s);
		}
	}
}
