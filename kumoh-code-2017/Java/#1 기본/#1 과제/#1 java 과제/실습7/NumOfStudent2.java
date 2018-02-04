import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class NumOfStudent2 
{
    public static void main(String[] args)
    {
        String fileName = "student.txt";
        String std_identity;
        String[] std_spliting = new String[500];
        String[] std_major = new String[100]; // �а�
	String[] tmp = new String[50];
        int[] std_grade = new int[100]; // �й�
        int[] std_birth = new int[100]; // ����
        
        int major_count = 1;
        int grade_count = 1;
        int birth_count = 1;
        int majorFrontCount = 0;
        int majorRearCount = 0;
        int num_of_grade1 = 0;
        int num_of_grade2 = 0;
        int num_of_grade3 = 0;
        int num_of_grade4 = 0;
        int n92 = 0;
        int n93 = 0;
        int n94 = 0;
        int n95 = 0;
        int n96 = 0;
        try {
        	std_identity = readContentFrom(fileName);
            
        	std_spliting = std_identity.split(":");
        	std_major[0] = std_spliting[0];
    		int temp = Integer.parseInt(std_spliting[1]);
    		std_grade[0] = temp;
    		
    		tmp = std_spliting[2].split("-");
    		int temp2 = Integer.parseInt(tmp[0]);
    		std_birth[0] = temp2;

            for(int i = 3; i < std_spliting.length; i++)
            {
            	if(i%3 == 0)
            	{
            		std_major[major_count] = std_spliting[i];
            		major_count++;
            	}
            	else if((i-1)%3 == 0)
            	{
            		int change = Integer.parseInt(std_spliting[i]);
            		std_grade[grade_count] = change;
            		grade_count++;
            	}
            	else if((i-2)%3 == 0)
            	{
            		tmp = std_spliting[i].split("-");
            		int change = Integer.parseInt(tmp[0]);
            		std_birth[birth_count] = change;
            		birth_count++;
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
            
            for(int i = 0; i < std_birth.length; i++)
            {
            	if(std_birth[i] == 1992)
            	{
            		n92++;
            	}
            	else if(std_birth[i] == 1993)
            	{
            		n93++;
            	}
            	else if(std_birth[i] == 1994)
            	{
            		n94++;
            	}
            	else if(std_birth[i] == 1995)
            	{
            		n95++;
            	}
            	else if(std_birth[i] == 1996)
            	{
            		n96++;
            	}
            	else
            	{
            		break;
            	}
            }
            
            System.out.println("SE �л����� " + majorFrontCount + "�� �Դϴ�.");
            System.out.println("CE �л����� " + majorRearCount + "�� �Դϴ�.");
            System.out.println();

            System.out.println("1�г� �л����� " + num_of_grade1 + "�� �Դϴ�.");
            System.out.println("2�г� �л����� " + num_of_grade2 + "�� �Դϴ�.");
            System.out.println("3�г� �л����� " + num_of_grade3 + "�� �Դϴ�.");
            System.out.println("4�г� �л����� " + num_of_grade4 + "�� �Դϴ�.");
            System.out.println();
            
            System.out.println("92����� " + n92 + "�� �Դϴ�.");
            System.out.println("93����� " + n93 + "�� �Դϴ�.");
            System.out.println("94����� " + n94 + "�� �Դϴ�.");
            System.out.println("95����� " + n95 + "�� �Դϴ�.");
            System.out.println("96����� " + n96 + "�� �Դϴ�.");
            System.out.println();
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
        StringBuilder sb= new StringBuilder();
        char[] buf = new char[1024];  

        while (br.read(buf) > 0) 
        {
        	sb.append(buf);
        } 
 
        return sb.toString();
    }
	
}
