import java.util.*;
import java.util.Collections;

public class ListTest
{
	public static void main(String[] args)
	{
		String[] colors = {"black", "yellow", "green", "blue", "violet", "silver"};
		List<String> list1 = new LinkedList<String>();
		for(String color : colors)
		{
			list1.add(color);
		}
		String[] colors2 = {"gold", "white", "brown", "blue", "gray", "silver"};
		List<String> list2 = new LinkedList<String>();
		for(String color : colors2)
		{
			list2.add(color);
		}
		
		list1.addAll(list2);	// concatenate lists
		list2 = null;			// release resources
		printList(list1);
		
		convertToUppercaseStrings(list1);
		printList(list1);
		
		sortItems(list1);
		printList(list1);
		
		shuffleItems(list1);
		printList(list1);
	}
	
	private static void printList(List<String> list) // list iteration
	{
		for(String color : list)
		{
			System.out.printf("%s", color);
			System.out.println();
		}
	}
	
	private static void convertToUppercaseStrings(List<String> list)
	{
		ListIterator<String> iterator = list.listIterator();
		while(iterator.hasNext())
		{
			String color = iterator.next();
			iterator.set(color.toUpperCase());
		}
	}
	
	private static void removeItems(List<String> list, int start, int end)
	{
		list.subList(start, end).clear();
	}
	
	private static void sortItems(List<String> list)
	{
		Collections.sort(list); // list의 원소를 정렬함
	}
	
	private static void shuffleItems(List<String> list)
	{
		Collections.shuffle(list); // list의 원소를 임의의 순서로 섞음
	}
	
	private static void printReverseList(List<String> list)
	{
		ListIterator<String> iterator = list.listIterator();
		while(iterator.hasPrevious())
		{
			System.out.printf("%s ", iterator.previous());
		}
	}
}
