import java.io.File;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class CountKeywords
{
	public static void main(String[] args) throws Exception
	{
		File file = new File(args[0]);
		if(file.exists()) System.out.println("키워드 개수 : " + countKeywords(file));
		else System.out.println(args[0] + "존재하지 않음");
	}
	
	public static int countKeywords(File file) throws Exception
	{
		String[] keywordString = { "abstract", "assert", "boolean", "break", "byte", "case", "catch",
				"char", "class", "const", "continue", "default", "do", "double", "else", "enum", "extends", "for", "final",
				"finally", "float", "goto", "if", "implements", "import", "instanceof", "int", "interface", "long", "native",
				"new", "package", "private", "protected", "public", "return", "short", "static", "strictfp", "super", "switch",
				"synchronized", "this", "throw", "throws", "transient", "try", "void", "volatile", "while", "true", "false", "null"
						};
		Set<String> keywordSet = new HashSet<>(Arrays.asList(keywordString));
		int count = 0;
		Scanner sc = new Scanner(file);
		while (sc.hasNext()) 
		{
			String word = sc.next();
			if (keywordSet.contains(word)) count++;
		}
		return count;
	}
}