package 수업;

import java.util.Scanner;

public class Circle extends Shape
{
	Scanner sc = new Scanner(System.in);
	
	public static double PI; // 3.14

	private double radius; // 반지름
	
	public Circle(){PI = 3.14;}
	
	public double getArea()
	{
		return radius * radius * PI;
	}
	public void setRadius(double radius)
	{
		this.radius = radius;
	}
	
	public void printCircle()
	{
		System.out.println("반지름 : " + radius);
		System.out.println("면적 : " + getArea());
	}
	
	public void showAll()
	{
		System.out.println("초기 상태");
		printCircle();
		
		System.out.print("반지름 입력 : ");
		double radius = sc.nextDouble();
		setRadius(radius);
		
		System.out.println("현재 상태");
		printCircle();
	}
}
