import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Scanning
{
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner s = new Scanner(new BufferedReader(new FileReader("a.dat")));
		
		double sum = 0;
		
		while(s.hasNext()) // EOF °Ë»ç
		{
			if(s.hasNextDouble())
			{
				sum += s.nextDouble();
			}
			else
			{
				s.next(); // skip next token
			}
		}
		
		System.out.println(sum);
	}
}
