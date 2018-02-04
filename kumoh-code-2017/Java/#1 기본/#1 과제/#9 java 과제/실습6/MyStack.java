import java.util.*;

public class MyStack<E>
{
	private List<E> elements;
	
	public MyStack(int capa)
	{
		elements = new ArrayList<E>(capa);
	}
	
	public void push(E e)
	{
		elements.add(e);
	}
	
	public E pop()
	{
		if(elements.isEmpty()) throw new RuntimeException("stack is empty");
		{
			return elements.remove(elements.size() - 1);
		}
	}
}
