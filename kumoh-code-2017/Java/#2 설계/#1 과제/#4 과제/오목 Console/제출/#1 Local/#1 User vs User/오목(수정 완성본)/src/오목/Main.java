package ����;

import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		MyMatch mm = new MyMatch();
		
		System.out.println("---------- ���� ���α׷�                    ----------");
		System.out.println("---------- �ٵ��� ũ�� ����                ----------");
		System.out.println("---------- 1. �⺻ ���� (19x19) ----------");
		System.out.println("---------- 2. ���� ���� (����)   ----------");
		System.out.print("���� : ");
		
		int sizeMenu = sc.nextInt();
		
		mm.play(sizeMenu);
	}
}
