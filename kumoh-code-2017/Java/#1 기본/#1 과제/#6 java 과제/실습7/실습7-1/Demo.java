import java.io.*;
import java.util.Scanner;

public class Demo
{
	public static void methodA()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("������ ���� 2���� �Է��Ͻÿ�. ");
		System.out.print("ù ��° ���� : ");
		int a = sc.nextInt();
		System.out.print("�� ��° ���� : ");
		int b = sc.nextInt();
		
		methodB(a,b);
	}
	
	public static void methodB(int a, int b)
	{
		try
		{
			int result = a/b; // 0���� ���� �� ���� �߻�
			System.out.println("��� : " + result);
		}
		catch(Exception e)
		{
			System.out.println("�߻��� ������ ���� ó��");
		}
	}
	public static void main(String[] args)
	{
		methodA();
	}
}
