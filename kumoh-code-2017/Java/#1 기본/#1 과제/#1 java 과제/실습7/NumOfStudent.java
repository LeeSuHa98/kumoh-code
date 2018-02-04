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
		String[] std_major = new String[100]; // 학과
		int[] std_grade = new int[100]; // 학년
		
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

			System.out.println("SE 학생수는 " + majorFrontCount + "명 입니다.");
			System.out.println("CE 학생수는 " + majorRearCount +  "명 입니다.");

			System.out.println("1학년 학생수는 " + num_of_grade1 + "명 입니다.");
			System.out.println("2학년 학생수는 " + num_of_grade2 + "명 입니다.");
			System.out.println("3학년 학생수는 " + num_of_grade3 + "명 입니다.");
			System.out.println("4학년 학생수는 " + num_of_grade4 + "명 입니다.");
		}

		catch (FileNotFoundException e) 
		{
			System.out.println(fileName + " 파일이 존재하지 않습니다."); 
			e.printStackTrace();
		}

		catch (IOException e) 
		{
			System.out.println(fileName + " 파일을 읽을 수 없습니다."); 
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
