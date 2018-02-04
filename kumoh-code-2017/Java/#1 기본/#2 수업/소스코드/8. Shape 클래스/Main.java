package 수업;

public class Main
{
	public static void main(String[] args)
	{
		Shape[] shape = {new Rectangle(), new Circle()};
		
		for(int i = 0; i < shape.length; i++)
		{
			shape[i].showAll();
		}
	}
}
