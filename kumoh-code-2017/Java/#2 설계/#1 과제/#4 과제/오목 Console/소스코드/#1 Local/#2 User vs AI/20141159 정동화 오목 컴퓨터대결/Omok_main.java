package practice;
import java.util.Scanner;

public class Omok_main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		Match match = new Match();;

		Player p1 = new Player();
		Player p2 = new Player();
		Position position = null;
		int id = 0;
		boolean checkBoardSize = false;
		boolean check = false;
		int id_position = -999;
		int checkOrder = 0;
		System.out.println("===현재 플레이어의 타입은 모두 사용자입니다. 컴퓨터와의 대결은 추후에 구현 될 예정입니다.===");
		while(true) {
			p1 = new Player();
			p2 = new Player();
			int count = 1; //게임진행횟수
			double result= 0;
			boolean playerCheck = false;
			int stoneNum = 0;
			System.out.println("==게임 타입선택 ==");
			System.out.println("1. 로컬게임 시작");
			System.out.println("2. 네트워크게임 시작");
			System.out.println("3. 종료");
			int choose = sc.nextInt();
			if(choose == 1) {
				match.setPlayType(choose);
				System.out.println("현재 게임모드(1. 로컬,2.네트워크) :"+match.getPlayType());
				while(!checkBoardSize) {
					System.out.println("바둑판의 크기설정 0=10*10,1=15*15,2=19*19");
					int size = sc.nextInt();
					if(size>=0||size<3) {
						match.setBoardSize(size);
						match = new Match(match.getBoardSize(),match.getBoardSize());
						checkBoardSize = true;
						break;
					}
					else
					{
						System.out.println("0~2사이의 숫자 입력");
					}
				}

				while(true) {
					System.out.println("게입타입 선택 1. 사람vs사람 2. 사람vs컴퓨터 3.종료");
					int chooseType = sc.nextInt();
					if(chooseType == 1) {
						while(true) {
							System.out.println("플레이어 선택 1. 기존플레이어로 생성, 2.새로운 플레이어 생성, 3.현재 저장되어있는 플레이어 출력");
							int pChoose = sc.nextInt();
							if(pChoose == 1) {
								if(id != 0) {
									System.out.println("찾고자 하는 플레이어의 아이디: ");
									int pId = sc.nextInt();
									for(int i=0;i<100;i++) {
										if(match.players[i].getId()== pId ) {			
											id_position = i;
											System.out.println("탐색완료");
											break;
										}
									}

								}
								else {
									System.out.println("현재 플레이어가 저장되어 있지 않습니다.");
								}
								if(id_position != -999) {
									if(p1.getGameCount() == 0) {
										p1 = new Player(match.players[id_position].getId(),match.players[id_position].getName(),1,match.players[id_position].getPlayerType(),StoneType.Black,match.players[id_position].getWinningRate());
										System.out.println("1번째 플레이어 설정완료");
										p1.gameCount++;
									}
									else if(p2.getGameCount() == 0) {
										p2 = new Player(match.players[id_position].getId(),match.players[id_position].getName(),2,match.players[id_position].getPlayerType(),StoneType.White,match.players[id_position].getWinningRate());
										if(p1.getId() != p2.getId()) {
											playerCheck = true;
											System.out.println("2번째 플레이어 설정완료");
											p2.gameCount++;
											break;
										}
										else {
											System.out.println("같은 이름끼리 대전할 수 없습니다.1번째 사용자부터 다시 정의해 주십시오");
											p1 = new Player();
											p2 = new Player();
										}
									}
								}
							}
							else if(pChoose == 2) {
								System.out.println("새로운 플레이어의 이름설정 : ");
								String name = sc.next();
								if(p1.getGameCount() == 0) {
									p1 = new Player(id,name,1,1,StoneType.Black,0.0);
									match.players[id] = p1;
									System.out.println("1번째 플레이어 설정완료");
									id++;
									p1.gameCount++;

								}
								else if(p2.getGameCount() == 0) {
									p2 = new Player(id,name,2,1,StoneType.White,0.0);
									match.players[id] = p2;
									playerCheck = true;
									id++;
									System.out.println("2번째 플레이어 설정완료");
									p2.gameCount++;
									break;
								}

							}
							else if(pChoose == 3) {
								if(id == 0)
								{
									System.out.println("현재 저장되어있는 플레이어가 없습니다.");
								}
								else {
									for(int i=0;i<100;i++) {
										if(match.players[i].getName() != null) {
											match.showPlayer(i);
										}
									}
								}
							}
							else
							{
								System.out.println("1또는 2 입력");
							}
						}


						if(playerCheck) {
							System.out.println("=====대전할 플레이어 정보출력=====");
							System.out.println("<아이디> "+p1.getId()+"<게임순서>"+p1.getOrder()+"<이름>"+p1.getName()+"<게임타입>"+p1.getPlayerType());
							System.out.println("<아이디> "+p2.getId()+"<게임순서>"+p2.getOrder()+"<이름>"+p2.getName()+"<게임타입>"+p2.getPlayerType());

							while(true) {
								System.out.println("1. 오목판 출력");
								System.out.println("2. 오목판에 돌 놓기(순서는 자동으로 변경됩니다.)");
								System.out.println("3. 종료");
								int start = sc.nextInt();
								if(start == 1) {
									match.showBoard();
									System.out.print("현재 바둑돌의 갯수: ");
									System.out.println(stoneNum);
								}
								else if(start == 2) {

									if(count %2 != 0) {
										System.out.println(p1.getName()+"플레이어의 차례입니다. 원하는 위치를 설정하세요");
										int r1 = sc.nextInt();
										int c1= sc.nextInt();

										position = new Position(r1,c1);
										if(match.checkValidity(position)) {
											match.registerStone(r1, c1, StoneType.Black);
											stoneNum++;
											count++;
										}
										else
										{
											System.out.println("이미 돌이 놓여져있습니다.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p1.getName()+"플레이어의 승리입니다.");
											for(int i = 0;i<100;i++) {
												if(match.players[i].getId() == p1.getId())
												{
													match.players[i].winCount++;
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);
												}
												else if(match.players[i].getId() == p2.getId()) {

													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);


												}
											}
											match.ClearBoard();
											playerCheck = false;
											break;
										}

									}
									else {
										System.out.println(p2.getName()+"플레이어의 차례입니다. 원하는 위치를 설정하세요");
										int r2 = sc.nextInt();
										int c2 = sc.nextInt();

										position = new Position(r2,c2);
										if(match.checkValidity(position)) {
											match.registerStone(r2, c2, StoneType.White);
											stoneNum++;
											count++;
										}
										else {
											System.out.println("이미 돌이 놓여져 있습니다.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p2.getName()+"플레이어의 승리입니다.");


											for(int i = 0;i<100;i++) {
												if(match.players[i].getId() == p1.getId())
												{
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);
												}
												else if(match.players[i].getId() == p2.getId()) {
													match.players[i].winCount++;
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);

												}
											}
											match.ClearBoard();
											playerCheck = false;
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
					else if(chooseType == 2) { 
						System.out.println("사람vs컴퓨터 의 싸움입니다.");
						System.out.println("플레이어의 이름 입력(순서까지입력, 컴퓨터의 순서는 자동으로 지정됨)");
						String name = sc.next();
						while(true) {
							System.out.println("순서 결정");
							int order = sc.nextInt();
							if(order == 1) {
								p1 = new Player(id,name,order,1,StoneType.Black,0.0);
								match.players[id] = p1;
								System.out.println("플레이어 설정완료");
								id++;
								p1.gameCount++;
								p2 = new ComputerPlayer(id,"컴퓨터"+id,order+1,2,StoneType.White,0.0);
								match.players[id] = p1;
								id++;
								p2.gameCount++;
								System.out.println("컴퓨터 설정완료");
								playerCheck = true;
								break;
							}
							else if(order == 2) {
								p2 = new ComputerPlayer(id,"컴퓨터"+id,order-1,2,StoneType.White,0.0);
								match.players[id] = p2;
								id++;
								p2.gameCount++;
								System.out.println("컴퓨터 설정완료");
								p1 = new Player(id,name,order,1,StoneType.Black,0.0);
								match.players[id] = p1;
								System.out.println("플레이어 설정완료");
								id++;
								p1.gameCount++;
								playerCheck = true;
								break;
							}
							else {
								System.out.println("1또는 2 입력");
								playerCheck = false;
							}
						}

						if(playerCheck) {
							System.out.println("=====대전할 플레이어 정보출력=====");
							System.out.println("<아이디> "+p1.getId()+"<게임순서>"+p1.getOrder()+"<이름>"+p1.getName()+"<게임타입>"+p1.getPlayerType());
							System.out.println("<아이디> "+p2.getId()+"<게임순서>"+p2.getOrder()+"<이름>"+p2.getName()+"<게임타입>"+p2.getPlayerType());
							System.out.println("플레이어가 돌을 놓은후 자동으로 컴퓨터가 돌은 놓습니다.");
							while(true) {
								System.out.println("1. 오목판 출력");
								System.out.println("2. 오목판에 돌 놓기(순서는 자동으로 변경됩니다.)");
								System.out.println("3. 종료");
								int start = sc.nextInt();
								if(start ==1) {
									match.showBoard();
									System.out.print("현재 바둑돌의 갯수: ");
									System.out.println(stoneNum);
								}
								else if(start == 2) {
									if(p1.getOrder() == 1) {
										System.out.println("플레이어의 차례입니다. 돌을 놓을 위치를 선택하세요");
										int r1 = sc.nextInt();
										int c1= sc.nextInt();

										position = new Position(r1,c1);
										if(match.checkValidity(position)) {
											match.registerStone(r1, c1, p1.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("이미 돌이 놓여져있습니다.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p1.getName()+"플레이어의 승리입니다.");
											for(int i = 0;i<100;i++) {
												if(match.players[i].getId() == p1.getId())
												{
													match.players[i].winCount++;
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);
												}
												else if(match.players[i].getId() == p2.getId()) {

													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);


												}
											}
											match.ClearBoard();
											playerCheck = false;
											break;
										}
										
										System.out.println("컴퓨터의 순서입니다 자동으로 돌을 놓습니다.");
										position = new Position(p2.play(match.getBoard()).getRow(),p2.play(match.getBoard()).getColumn());
										if(match.checkValidity(position)) {
											match.registerStone(position.getRow(),position.getColumn(),p2.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("이미 돌이 놓여져있습니다.");
										}
										
										if(match.checkWinningCondition(position))
										{
											System.out.println(p2.getName()+"플레이어의 승리입니다.");


											for(int i = 0;i<100;i++) {
												if(match.players[i].getId() == p1.getId())
												{
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);
												}
												else if(match.players[i].getId() == p2.getId()) {
													match.players[i].winCount++;
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);

												}
											}
											match.ClearBoard();
											playerCheck = false;
											break;
										}
									}
									else if(p1.getOrder() == 2) {

										System.out.println("컴퓨터의 순서입니다 자동으로 돌을 놓습니다.");
										position = new Position(p2.play(match.getBoard()).getRow(),p2.play(match.getBoard()).getColumn());
										if(match.checkValidity(position)) {
											match.registerStone(position.getRow(), position.getColumn(),p2.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("이미 돌이 놓여져있습니다.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p2.getName()+"플레이어의 승리입니다.");


											for(int i = 0;i<100;i++) {
												if(match.players[i].getId() == p1.getId())
												{
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);
												}
												else if(match.players[i].getId() == p2.getId()) {
													match.players[i].winCount++;
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);

												}
											}
											match.ClearBoard();
											playerCheck = false;
											break;
										}
										System.out.println("플레이어의 차례입니다. 돌을 놓을 위치를 선택하세요");
										int r1 = sc.nextInt();
										int c1= sc.nextInt();

										position = new Position(r1,c1);
										if(match.checkValidity(position)) {
											match.registerStone(r1, c1, p1.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("이미 돌이 놓여져있습니다.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p1.getName()+"플레이어의 승리입니다.");
											for(int i = 0;i<100;i++) {
												if(match.players[i].getId() == p1.getId())
												{
													match.players[i].winCount++;
													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);
												}
												else if(match.players[i].getId() == p2.getId()) {

													match.players[i].gameCount++;
													match.players[i].winningRate = match.players[i].winCount*100/(match.players[i].gameCount-1);


												}
											}
											match.ClearBoard();
											playerCheck = false;
											break;
										}
									}
								}
								else if(start == 3) {
									break;
								}
								else {
									System.out.println("1~3사이의 숫자입력");
								}
							}

						}
					}
					else if(chooseType == 3) {
						break;
					}
					else {
						System.out.println("1~3사이의 숫자입력");
					}

				}
			}
			else if(choose == 2) {
				match.setPlayType(choose);
				System.out.println("현재 게임모드(1. 로컬,2.네트워크) :"+match.getPlayType());
				System.out.println("네트워크모드는 아직 미구현 상태입니다.");
			}
			else if(choose == 3) {
				match.ClearBoard();
				break;
			}
			else
			{
				System.out.println("1~3사이의 숫자입력");
			}

		}
		sc.close();

	}

}
