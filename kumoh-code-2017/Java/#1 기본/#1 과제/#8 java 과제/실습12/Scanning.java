import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Scanning
{
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner s = new Scanner(new FileReader("a.dat"));
		
		while(s.hasNextFloat())
		{
			System.out.println(s.nextFloat());
		}
	}
}
