public class StackDemo
{
	public static void main(String[] args) throws Exception
	{
		MyStack<Integer> s = new MyStack<Integer>(10);
		s.push(1); s.push(2); s.push(3);
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		
		MyStack<Double> s2 = new MyStack<Double>(2);
		s2.push(1.1); s2.push(2.2); s2.push(3.3); s2.push(4.4);
		System.out.println(s2.pop());
		System.out.println(s2.pop());
		System.out.println(s2.pop());
		System.out.println(s2.pop());
		System.out.println(s2.pop());
	}
}
