public class Circle extends Shape
{
	static final double PI = 3.14159;
	private int radius;
	
	public Circle(int radius)
	{
		this.radius = radius;
	}
	
	public double getArea()
	{
		return radius * radius * PI;
	}
}
