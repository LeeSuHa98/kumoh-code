package 학생관리;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ioHandler
{
	Scanner sc = new Scanner(System.in);
	
	public int getMenu()
	{
		System.out.println("----- 학생관리 프로그램 -----");
		System.out.println("----- 1. 학생정보 등록 -----");
		System.out.println("----- 2. 학생정보 삭제 -----");
		System.out.println("----- 3. 학생정보 수정 -----");
		System.out.println("----- 4. 학생정보 출력 -----");
		System.out.println("----- 5. 종료            -----");
		
		int menu = getInteger("선택 : ");
		if(menu >= 1 && 5 >= menu)
		{
			return menu;
		}
		return 0;
	}
	
	public Student getStudent()
	{
		System.out.println("학번 : ");
		int id = sc.nextInt();
		
		System.out.println("이름 : ");
		String name = sc.next();
		
		System.out.println("나이 : ");
		int age = sc.nextInt();
		
		System.out.println("전화번호 : ");
		String phone = sc.next();
		
		Student s = new Student(id, name, age, phone);
		
		return s;
	}
	
	public void putStudent(Student s)
	{
		System.out.println("학번 : " + s.getId());
		System.out.println("이름 : " + s.getName());
		System.out.println("나이 : " + s.getAge());
		System.out.println("전화번호 : " + s.getPhone());
		System.out.println("\n");
	}
	
	public String getString(String msg)
	{
		String value;
		
		System.out.println(msg);
		value = sc.next();
		
		return value;
	}
	
	public int getInteger(String msg)
	{
		int value;
		
		System.out.println(msg);
		value = sc.nextInt();
		
		return value;
	}
	
	public void loadStudent(String fileName, StudentList s_list) throws IOException
	{
		FileReader fr = new FileReader(fileName);
		
		BufferedReader br = new BufferedReader(fr);
		br.close();
		
		while(true)
		{
			int id = br.read();
			String name = br.readLine();
			int age = br.read();
			String phone = br.readLine();
				
			Student s = new Student(id, name, age, phone);
			s_list.insertStudent(s);			
		}
	}
	
	public void saveStudent(String fileName, StudentList s_list) throws IOException
	{
		PrintWriter pw = new PrintWriter(fileName);
		
		for(int i = 0; i < s_list.getCount(); i++)
		{
			pw.println(s_list.getStudentList(i).getId());
			pw.println(s_list.getStudentList(i).getName());
			pw.println(s_list.getStudentList(i).getAge());
			pw.println(s_list.getStudentList(i).getPhone());
		}
		pw.close();
	}
}
