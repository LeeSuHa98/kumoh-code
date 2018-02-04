public class Main
{
	public static void main(String[] args)
	{
		Rectangle r1 = new Rectangle();
		System.out.println("Rectangle 1 of Size : " + r1.findArea(10));
		Rectangle r2 = new Rectangle();
		System.out.println("Rectangle 2 of Size : " + r2.findArea(10, 20));
		Rectangle r3 = new Rectangle();
		System.out.println("Rectangle 3 of Size : " + r3.findArea(10.5, 10));
	}
}