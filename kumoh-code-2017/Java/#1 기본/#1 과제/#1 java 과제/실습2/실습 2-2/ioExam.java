// [�ǽ� 2 - �����]
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ioExam
{
	public static void main(String[] args) throws IOException
	{
		String fileName = "student.txt";

		try
		{
			FileReader fr = new FileReader(fileName);

			BufferedReader br = new BufferedReader(fr);

			while(true)
			{
				System.out.println("�ؽ�Ʈ ������ �о���Դϴ�.");
				
				String major = br.readLine();
				if(major==null) break;
				System.out.println("�а� : " + major);
				
				String grade = br.readLine();
				if(grade==null)break;
				System.out.println("�г� : " + grade);
				
				String id = br.readLine();
				if(id==null) break;
				System.out.println("�й� : " + id);
				
				String name = br.readLine();
				if(name==null) break;
				System.out.println("�̸� : " + name);
				
				String sex = br.readLine();
				if(sex==null) break;
				System.out.println("���� : " + sex);
				
				String birth = br.readLine();
				if(birth==null) break;
				System.out.println("���� : " + birth);
				
				String weight = br.readLine();
				if(weight==null) break;
				System.out.println("ü�� : " + weight);
				
				String address = br.readLine();
				if(address==null) break;
				System.out.println("�ּ� : " + address);
			}
			
			br.close();
		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
