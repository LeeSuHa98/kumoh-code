import java.util.ArrayList;

public class ArrayListDemo
{
	public static void main(String[] args)
	{
		// A dynamic array of String; 용량 = 10 by default.
		ArrayList<String> items = new ArrayList<String>();
		
		items.add("red");		// append an item to the list
		items.add(0, "yellow");	// positional insert the value at index 0
		
		for(int i = 0; i < items.size(); i++)
		{
			System.out.printf("%s", items.get(i));
		}
		
		items.add("green");
		items.add("yellow");
		
		items.remove("yellow");	// remove the first "yellow"
		items.remove(1);		// remove item at index 1
		
		System.out.println(items.contains("red")); // 존재여부 확인
		System.out.printf("Size: %s\n", items.size());
	}
}
