import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

public class StackDemo
{
	public static void main(String[] args)
	{
		Deque<Integer> stack = new LinkedList<Integer>();
//		Deque<Integer> stack = new ArrayDeque<>(Integer);
		
		// Deque 인터페이스의 addFirst(), removeFirst() 사용
		stack.addFirst(3); // head에 추가
		stack.addFirst(1);
		stack.addFirst(5);
		
		while(!stack.isEmpty())
		{
			System.out.println(stack.removeFirst());	// head에서 제거
		}
	}
}
