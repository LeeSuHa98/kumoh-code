import java.util.Comparator;

public class ShapeComparator implements Comparator<Shape>
{
	public int compare(Shape o1, Shape o2)
	{
		double area1 = o1.getArea();
		double area2 = o2.getArea();
		
		if(area1 < area2) return -1;
		else if (area1 == area2) return 0;
		else return 1;
	}
}
