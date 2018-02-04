import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

public class DequeDemo
{
	public static void main(String[] args)
	{
		Deque<Integer> queue = new LinkedList<Integer>();
//		Deque<Integer> queue = new ArrayDeque<Integer>();
		
		
		// Deque 인터페이스의 addFirst(), removeFirst() 사용
		queue.addLast(3); // tail에 추가
		queue.addLast(1);
		queue.addLast(5);
		while(!queue.isEmpty())
		{
			System.out.println(queue.removeFirst());	// head에서 제거
		}
	}
}
