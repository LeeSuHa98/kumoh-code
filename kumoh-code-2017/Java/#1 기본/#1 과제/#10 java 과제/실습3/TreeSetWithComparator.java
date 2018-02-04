import java.util.*;

public class TreeSetWithComparator
{
	public static void main(String[] args)
	{
		Set<Shape> set = new TreeSet<>(new ShapeComparator());
		
		set.add(new Rectangle(4, 5));
		set.add(new Circle(40));
		
		set.add(new Circle(40));
		set.add(new Rectangle(4, 1));
		
		for(Shape element: set)
		{
			System.out.println("area = " + element.getArea());
		}
	}
}
