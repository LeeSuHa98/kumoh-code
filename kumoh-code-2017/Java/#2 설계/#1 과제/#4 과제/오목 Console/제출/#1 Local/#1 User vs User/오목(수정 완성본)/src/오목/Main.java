package 오목;

import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		MyMatch mm = new MyMatch();
		
		System.out.println("---------- 오목 프로그램                    ----------");
		System.out.println("---------- 바둑판 크기 설정                ----------");
		System.out.println("---------- 1. 기본 설정 (19x19) ----------");
		System.out.println("---------- 2. 임의 설정 (선택)   ----------");
		System.out.print("선택 : ");
		
		int sizeMenu = sc.nextInt();
		
		mm.play(sizeMenu);
	}
}
