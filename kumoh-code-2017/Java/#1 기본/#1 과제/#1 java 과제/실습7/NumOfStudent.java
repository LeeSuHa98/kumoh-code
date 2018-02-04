import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class NumOfStudent 
{
	public static void main(String[] args)
	{
		String fileName = "student.txt";
		String std_identity;
		String[] std_split = new String[500];
		String[] std_major = new String[100]; // �а�
		int[] std_grade = new int[100]; // �г�
		
		int major_count = 1;
		int grade_count = 1;
		int majorFrontCount = 0;
		int majorRearCount = 0;
		int num_of_grade1 = 0;
		int num_of_grade2 = 0;
		int num_of_grade3 = 0;
		int num_of_grade4 = 0;

		try {
			std_identity = readContentFrom(fileName);

			std_split = std_identity.split(":");
			std_major[0] = std_split[0];
			int tmp = Integer.parseInt(std_split[1]);
			std_grade[0] = tmp;

			for(int i = 3; i < std_split.length; i++)
			{
				if(i%3 == 0)
				{
					std_major[major_count] = std_split[i];
					major_count++;
				}
				else if((i-1)%3 == 0)
				{
					int change = Integer.parseInt(std_split[i]);
					std_grade[grade_count] = change;
					grade_count++;
				}
			}

			for(int i = 0; i < std_major.length; i++)
			{
				if(std_major[i].equals("SE"))
				{
					majorFrontCount++;
				}
				else if(std_major[i].equals("CE"))
				{
					majorRearCount++;
				}
				else
				{
					break;
				}
			}

			for(int i = 0; i < std_grade.length; i++)
			{
				if(std_grade[i] == 1)
				{
					num_of_grade1++;
				}
				else if(std_grade[i] == 2)
				{
					num_of_grade2++;
				}
				else if(std_grade[i] == 3)
				{
					num_of_grade3++;
				}
				else if(std_grade[i] == 4)
				{
					num_of_grade4++;
				}
				else
				{
					break;
				}
			}

			System.out.println("SE �л����� " + majorFrontCount + "�� �Դϴ�.");
			System.out.println("CE �л����� " + majorRearCount +  "�� �Դϴ�.");

			System.out.println("1�г� �л����� " + num_of_grade1 + "�� �Դϴ�.");
			System.out.println("2�г� �л����� " + num_of_grade2 + "�� �Դϴ�.");
			System.out.println("3�г� �л����� " + num_of_grade3 + "�� �Դϴ�.");
			System.out.println("4�г� �л����� " + num_of_grade4 + "�� �Դϴ�.");
		}

		catch (FileNotFoundException e) 
		{
			System.out.println(fileName + " ������ �������� �ʽ��ϴ�."); 
			e.printStackTrace();
		}

		catch (IOException e) 
		{
			System.out.println(fileName + " ������ ���� �� �����ϴ�."); 
			e.printStackTrace();
		}
	}

	public static String readContentFrom(String fileName) throws IOException 
	{
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		StringBuilder sb = new StringBuilder();
		char[] buf = new char[1024];  

		while (br.read(buf) > 0) 
		{
			sb.append(buf);
		} 

		return sb.toString();
	}
}
