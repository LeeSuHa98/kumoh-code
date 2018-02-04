package �л�����;
import java.util.Scanner;

public class StudentList
{
	final int MAX_STUDENT = 100;
	
	private Student[] student_list = new Student[MAX_STUDENT];
	private int count;
	
	public StudentList(){count = 0;}
	public int getCount(){return count;}
	public Student getStudentList(int index){return student_list[index];}
	
	public void insertStudent(Student s) // �л����
	{
		student_list[count] = s;
		count++;
	}
	
	public void deleteStudent(int index) // �л�����
	{
		student_list[index] = student_list[index+1];
		count--;
	}
	
	public void updateStudent(int index, Student s) // �л�����
	{
		student_list[index] = s;
	}
}
