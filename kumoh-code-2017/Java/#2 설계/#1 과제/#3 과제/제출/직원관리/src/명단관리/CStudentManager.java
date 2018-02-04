package 명단관리;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class CStudentManager
{
	private static final int MAX_SIZE = 100;
	private Student[] studentList = new Student[MAX_SIZE];
	private int count = 0;

	public void loadStudentFile(String fileName)
	{
		BufferedReader br = null;
		try {

			FileInputStream fin = new FileInputStream(fileName);
			br = new BufferedReader(new InputStreamReader(fin));
			
			String patchLine;
			String seperator = ",";
			
			while((patchLine = br.readLine()) != null)
			{
				String[] item = patchLine.split(seperator);
				String memberType = item[1];
				
				if(memberType.equals("학부") || memberType.equals("대학원"))
				{
					String id = item[0];
					String type = item[1];
					String name = item[2];
					int grade = Integer.parseInt(item[3]);
					String advisor = item[4];
					String address = item[5];
					double credit = Double.parseDouble(item[6]);
					if(item.length > 7)
					{
						String study = item[7];
						insertStudent(id, type, name, grade, advisor, address, credit, study);
					}
					else
					{
						insertStudent(id, type, name, grade, advisor, address, credit);
					}
				}
				else if(memberType.equals("산업대학원"))
				{
					String id = item[0];
					String type = item[1];
					String name = item[2];
					int grade = Integer.parseInt(item[3]);
					String advisor = item[4];
					String address = item[5];
					double credit = Double.parseDouble(item[6]);
					String company = item[8];
					String department = item[9];
					String position = item[10];
					if(item.length > 10)
					{
						String major = item[7];
						insertStudent(id, type, name, grade, advisor, address, credit, major, company, department, position);
					}
					else
					{
						insertStudent(id, type, name, grade, advisor, address, credit, company, department, position);
					}
				}
			}
		} 
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				if(br != null)
				{ 
					br.close(); 
				}
			}
			catch (IOException e) 
			{ 
				System.out.println("Failed to close file!!"); 
			}
		}
	}
	
	public void saveStudentFile(String fileName)
	{
		BufferedWriter br = null;
		try
		{
			FileOutputStream fout = new FileOutputStream(fileName);
			br = new BufferedWriter(new OutputStreamWriter(fout));

			for(int i = 0 ; i < count ; i++)
			{
				String str = studentList[i].getShowOfStringData();
				br.write(str);
				br.newLine();
			}
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				if(br != null)
				{ 
					br.close();
				}
			}
			catch (IOException e) 
			{
				System.out.println("Failed to close file!!"); 
			}
		}
	}
	
	public void insertStudent(String id, String type, String name, int grade, String advisor, String address, double credit, String study)
	{
		if(type.equals("대학원"))
		{
			Student s = new Graduate(id, type, name, grade, advisor, address, credit, study);
			studentList[count] = s;
			count++;
		}
		else if(type.equals("학부"))
		{
			Student s = new Under(id, type, name, grade, advisor, address, credit, study);
			studentList[count] = s;
			count++;
		}
	}
	public void insertStudent(String id, String type, String name, int grade, String advisor, String address, double credit)
	{
		if(type.equals("대학원"))
		{
			Student s = new Graduate(id, type, name, grade, advisor, address, credit, "");
			studentList[count] = s;
			count++;
		}
		else if(type.equals("학부"))
		{
			Student s = new Under(id, type, name, grade, advisor, address, credit, "");
			studentList[count] = s;
			count++;
		}
	}
	public void insertStudent(String id, String type, String name, int grade, String advisor, String address, double credit, String major, String company, String department, String position)
	{
		Student s = new IndustryGraduate(id, type, name, grade, advisor, address, credit, major, company, department, position);
		studentList[count] = s;
		count++;
	}
	public void insertStudent(String id, String type, String name, int grade, String advisor, String address, double credit, String company, String department, String position)
	{
		Student s = new IndustryGraduate(id, type, name, grade, advisor, address, credit, "", company, department, position);
		studentList[count] = s;
		count++;
	}
	
	public void deleteStudent(String id)
	{
		for(int i = 0; i < count; i++)
		{
			if(studentList[i].id == id)	// findStudent
			{
				for(int j = i; j < count; j++)
				{
					studentList[j] = studentList[j + 1];
				}
				count--;
				break;
			}
		}
	}
	
	public void printStudent()
	{
		for(int i = 0; i < count; i++)
		{
			studentList[i].show();
		}
	}
	
	public void clearAll()
	{
		count = 0;
	}
	
	public void sortByGPA()
	{
		for(int i = 0 ; i < count-1 ; i++)   //선택정렬
		{
			double credit1 = studentList[i].credit;
			for(int j = i + 1; j < count ; j++)
			{
				double credit2 = studentList[j].credit;
				
				if(credit1 >= credit2)
				{
					Student temp;
					temp = studentList[i];
					studentList[i] = studentList[j];
					studentList[j] = temp;
				}
			}
		}
	}
	
	public void searchByAdvisor(String advisor)
	{
		for(int i = 0; i < count; i++)
		{
			if(studentList[i].advisor == advisor)
			{
				studentList[i].show();
			}
		}
	}
}
