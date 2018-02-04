package 수업;

import java.util.Scanner;

public class Rectangle extends Shape
{
	Scanner sc = new Scanner(System.in);
	
	private int width; // 가로
	private int height; // 세로
	
	public Rectangle(){}
	
	public int getArea()
	{
		return width * height;
	}
	public void setWidth(int width)
	{
		this.width = width;
	}
	public void setHeight(int height)
	{
		this.height = height;
	}
	
	public void printRectangle()
	{
		System.out.println("가로 : " + width);
		System.out.println("세로 : " + height);
		System.out.println("면적 : " + getArea());
	}
	
	public void showAll()
	{
		System.out.println("초기 상태");
		printRectangle();
		
		System.out.print("가로 입력 : ");
		int width = sc.nextInt();
		setWidth(width);
		System.out.print("세로 입력 : ");
		int height = sc.nextInt();
		setHeight(height);
		
		System.out.println("현재 상태");
		printRectangle();
	}
}
