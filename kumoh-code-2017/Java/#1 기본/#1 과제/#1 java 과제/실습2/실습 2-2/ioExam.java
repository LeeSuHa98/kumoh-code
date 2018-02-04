// [실습 2 - 입출력]
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
				System.out.println("텍스트 파일을 읽어들입니다.");
				
				String major = br.readLine();
				if(major==null) break;
				System.out.println("학과 : " + major);
				
				String grade = br.readLine();
				if(grade==null)break;
				System.out.println("학년 : " + grade);
				
				String id = br.readLine();
				if(id==null) break;
				System.out.println("학번 : " + id);
				
				String name = br.readLine();
				if(name==null) break;
				System.out.println("이름 : " + name);
				
				String sex = br.readLine();
				if(sex==null) break;
				System.out.println("성별 : " + sex);
				
				String birth = br.readLine();
				if(birth==null) break;
				System.out.println("생일 : " + birth);
				
				String weight = br.readLine();
				if(weight==null) break;
				System.out.println("체중 : " + weight);
				
				String address = br.readLine();
				if(address==null) break;
				System.out.println("주소 : " + address);
			}
			
			br.close();
		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
