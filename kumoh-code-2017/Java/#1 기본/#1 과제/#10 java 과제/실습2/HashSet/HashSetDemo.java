import java.io.IOException;
import java.util.*;

public class HashSetDemo
{
	public static void main(String[] args) throws IOException
	{
		Set<String> s = new HashSet<>();

		for(String a : args)
		{
			if(!s.add(a))
			{
				System.out.println("중복원소: " + a);
			}
		}
		System.out.println(s.size() + "words: " + s);
	}
}
