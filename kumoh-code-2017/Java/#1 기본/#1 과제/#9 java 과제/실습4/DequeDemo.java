import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

public class DequeDemo
{
	public static void main(String[] args)
	{
		Deque<Integer> queue = new LinkedList<Integer>();
//		Deque<Integer> queue = new ArrayDeque<Integer>();
		
		
		// Deque �������̽��� addFirst(), removeFirst() ���
		queue.addLast(3); // tail�� �߰�
		queue.addLast(1);
		queue.addLast(5);
		while(!queue.isEmpty())
		{
			System.out.println(queue.removeFirst());	// head���� ����
		}
	}
}
