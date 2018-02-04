package practice;

import java.util.Scanner;

public class Omok_main {

	@SuppressWarnings("unused")
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StoneType s1 = null;
		StoneType s2 = null;
		Match match = new Match();
		Player p1 = new Player();
		Player p2 = new Player();
		Position position = null;
		int id = 0;
		boolean playerCheck = false;
		int count = 1; //게임진행횟수
		
		while(true) {
			System.out.println("==게임 타입선택 ==");
			System.out.println("1. 로컬게임 시작");
			System.out.println("2. 네트워크게임 시작");
			System.out.println("3. 종료");
			int choose = sc.nextInt();
			if(choose == 1) {
				match.setPlayType(choose);
				System.out.println("현재 게임모드(1. 로컬,2.네트워크) :"+match.getPlayType());
				System.out.println("바둑판의 크기설정 0=10*10,1=15*15,2=19*19");
				int size = sc.nextInt();
				match.setBoardSize(size);
				match = new Match(match.getBoardSize(),match.getBoardSize());
				
				
				System.out.println("1번째 플레어의 이름설정 : ");
				String name = sc.next();
				System.out.println("2번째 플레이어 이름설정: ");
				String name1 = sc.next();
				
				System.out.println("1번째 플레이어의 돌 선택 1.흑돌 2.백돌(2번째 플레이어는 자동으로 설정됩니다.)");
				int chooseStone = sc.nextInt();
				
				if(chooseStone == 1) {
					s1 = StoneType.Black;
					s2 = StoneType.White;
					p1 = new Player(id,name,1,1,s1);
					id++;
					p2 = new Player(id,name1,2,1,s2);
					playerCheck = true;
				}
				else if(chooseStone == 2) {
					s1 = StoneType.White;
					s2 = StoneType.Black;
					p1 = new Player(id,name,1,1,s1);
					id++;
					p2 = new Player(id,name,2,1,s2);
					playerCheck = true;
				}
				else
				{
					System.out.println("1또는 2 입력");
				}
				if(playerCheck) {
					while(true) {
						System.out.println("1. 오목판 출력");
						System.out.println("2. 오목판에 돌 놓기(순서는 자동으로 변경됩니다.)");
						System.out.println("3. 종료");
						int start = sc.nextInt();
						if(start == 1) {
							match.showBoard();
							System.out.print("현재 바둑돌의 갯수: ");
							System.out.println(count-1);
						}
						else if(start == 2) {
							if(count %2 != 0) {
								System.out.println("1번째 플레이어의 차례입니다. 원하는 위치를 설정하세요");
								int r = sc.nextInt();
								int c = sc.nextInt();
								position = new Position(r,c);
								if(match.checkValidity(position)) {
								match.registerStone(r, c, s1);
								count++;
								}
								else
								{
									System.out.println("이미 돌이 놓여져있습니다.");
								}
								if(match.checkWinningCondition(position))
								{
									System.out.println("1번째 플레이어의 승리입니다.");
									System.out.println("현재 플레이어의 승률"+p1.getWinningRate());
									break;
									
								}
							}
							else {
								System.out.println("2번째 플레이어의 차례입니다. 원하는 위치를 설정하세요");
								int r = sc.nextInt();
								int c = sc.nextInt();
								position = new Position(r,c);
								if(match.checkValidity(position)) {
								match.registerStone(r, c, s2);
								count++;
								}
								else {
									System.out.println("이미 돌이 놓여져 있습니다.");
								}
								if(match.checkWinningCondition(position))
								{
									System.out.println("2번째 플레이어의 승리입니다.");
									System.out.println("현재 플레이어의 승률"+p1.getWinningRate());
									break;

								}
							}
						}
						else if(start == 3) {
							break;
						}
						else
						{
							System.out.println("1~3사이의ㅡ 숫자입력");
						}
					}
				}
				
			}
			else if(choose == 2) {
				match.setPlayType(choose);
				System.out.println("현재 게임모드(1. 로컬,2.네트워크) :"+match.getPlayType());
				System.out.println("네트워크모드는 아직 미구현 상태입니다.");
			}
			else if(choose == 3) {
				break;
			}
			else
			{
				System.out.println("1~3사이의 숫자입력");
			}
		}
		
	}
	
}
