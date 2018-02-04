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
		System.out.println("===���� �÷��̾��� Ÿ���� ��� ������Դϴ�. ��ǻ�Ϳ��� ����� ���Ŀ� ���� �� �����Դϴ�.===");
		while(true) {
			p1 = new Player();
			p2 = new Player();
			int count = 1; //��������Ƚ��
			double result= 0;
			boolean playerCheck = false;
			int stoneNum = 0;
			System.out.println("==���� Ÿ�Լ��� ==");
			System.out.println("1. ���ð��� ����");
			System.out.println("2. ��Ʈ��ũ���� ����");
			System.out.println("3. ����");
			int choose = sc.nextInt();
			if(choose == 1) {
				match.setPlayType(choose);
				System.out.println("���� ���Ӹ��(1. ����,2.��Ʈ��ũ) :"+match.getPlayType());
				while(!checkBoardSize) {
					System.out.println("�ٵ����� ũ�⼳�� 0=10*10,1=15*15,2=19*19");
					int size = sc.nextInt();
					if(size>=0||size<3) {
						match.setBoardSize(size);
						match = new Match(match.getBoardSize(),match.getBoardSize());
						checkBoardSize = true;
						break;
					}
					else
					{
						System.out.println("0~2������ ���� �Է�");
					}
				}

				while(true) {
					System.out.println("����Ÿ�� ���� 1. ���vs��� 2. ���vs��ǻ�� 3.����");
					int chooseType = sc.nextInt();
					if(chooseType == 1) {
						while(true) {
							System.out.println("�÷��̾� ���� 1. �����÷��̾�� ����, 2.���ο� �÷��̾� ����, 3.���� ����Ǿ��ִ� �÷��̾� ���");
							int pChoose = sc.nextInt();
							if(pChoose == 1) {
								if(id != 0) {
									System.out.println("ã���� �ϴ� �÷��̾��� ���̵�: ");
									int pId = sc.nextInt();
									for(int i=0;i<100;i++) {
										if(match.players[i].getId()== pId ) {			
											id_position = i;
											System.out.println("Ž���Ϸ�");
											break;
										}
									}

								}
								else {
									System.out.println("���� �÷��̾ ����Ǿ� ���� �ʽ��ϴ�.");
								}
								if(id_position != -999) {
									if(p1.getGameCount() == 0) {
										p1 = new Player(match.players[id_position].getId(),match.players[id_position].getName(),1,match.players[id_position].getPlayerType(),StoneType.Black,match.players[id_position].getWinningRate());
										System.out.println("1��° �÷��̾� �����Ϸ�");
										p1.gameCount++;
									}
									else if(p2.getGameCount() == 0) {
										p2 = new Player(match.players[id_position].getId(),match.players[id_position].getName(),2,match.players[id_position].getPlayerType(),StoneType.White,match.players[id_position].getWinningRate());
										if(p1.getId() != p2.getId()) {
											playerCheck = true;
											System.out.println("2��° �÷��̾� �����Ϸ�");
											p2.gameCount++;
											break;
										}
										else {
											System.out.println("���� �̸����� ������ �� �����ϴ�.1��° ����ں��� �ٽ� ������ �ֽʽÿ�");
											p1 = new Player();
											p2 = new Player();
										}
									}
								}
							}
							else if(pChoose == 2) {
								System.out.println("���ο� �÷��̾��� �̸����� : ");
								String name = sc.next();
								if(p1.getGameCount() == 0) {
									p1 = new Player(id,name,1,1,StoneType.Black,0.0);
									match.players[id] = p1;
									System.out.println("1��° �÷��̾� �����Ϸ�");
									id++;
									p1.gameCount++;

								}
								else if(p2.getGameCount() == 0) {
									p2 = new Player(id,name,2,1,StoneType.White,0.0);
									match.players[id] = p2;
									playerCheck = true;
									id++;
									System.out.println("2��° �÷��̾� �����Ϸ�");
									p2.gameCount++;
									break;
								}

							}
							else if(pChoose == 3) {
								if(id == 0)
								{
									System.out.println("���� ����Ǿ��ִ� �÷��̾ �����ϴ�.");
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
								System.out.println("1�Ǵ� 2 �Է�");
							}
						}


						if(playerCheck) {
							System.out.println("=====������ �÷��̾� �������=====");
							System.out.println("<���̵�> "+p1.getId()+"<���Ӽ���>"+p1.getOrder()+"<�̸�>"+p1.getName()+"<����Ÿ��>"+p1.getPlayerType());
							System.out.println("<���̵�> "+p2.getId()+"<���Ӽ���>"+p2.getOrder()+"<�̸�>"+p2.getName()+"<����Ÿ��>"+p2.getPlayerType());

							while(true) {
								System.out.println("1. ������ ���");
								System.out.println("2. �����ǿ� �� ����(������ �ڵ����� ����˴ϴ�.)");
								System.out.println("3. ����");
								int start = sc.nextInt();
								if(start == 1) {
									match.showBoard();
									System.out.print("���� �ٵϵ��� ����: ");
									System.out.println(stoneNum);
								}
								else if(start == 2) {

									if(count %2 != 0) {
										System.out.println(p1.getName()+"�÷��̾��� �����Դϴ�. ���ϴ� ��ġ�� �����ϼ���");
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
											System.out.println("�̹� ���� �������ֽ��ϴ�.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p1.getName()+"�÷��̾��� �¸��Դϴ�.");
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
										System.out.println(p2.getName()+"�÷��̾��� �����Դϴ�. ���ϴ� ��ġ�� �����ϼ���");
										int r2 = sc.nextInt();
										int c2 = sc.nextInt();

										position = new Position(r2,c2);
										if(match.checkValidity(position)) {
											match.registerStone(r2, c2, StoneType.White);
											stoneNum++;
											count++;
										}
										else {
											System.out.println("�̹� ���� ������ �ֽ��ϴ�.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p2.getName()+"�÷��̾��� �¸��Դϴ�.");


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
									System.out.println("1~3�����Ǥ� �����Է�");
								}
							}
						}
					}
					else if(chooseType == 2) { 
						System.out.println("���vs��ǻ�� �� �ο��Դϴ�.");
						System.out.println("�÷��̾��� �̸� �Է�(���������Է�, ��ǻ���� ������ �ڵ����� ������)");
						String name = sc.next();
						while(true) {
							System.out.println("���� ����");
							int order = sc.nextInt();
							if(order == 1) {
								p1 = new Player(id,name,order,1,StoneType.Black,0.0);
								match.players[id] = p1;
								System.out.println("�÷��̾� �����Ϸ�");
								id++;
								p1.gameCount++;
								p2 = new ComputerPlayer(id,"��ǻ��"+id,order+1,2,StoneType.White,0.0);
								match.players[id] = p1;
								id++;
								p2.gameCount++;
								System.out.println("��ǻ�� �����Ϸ�");
								playerCheck = true;
								break;
							}
							else if(order == 2) {
								p2 = new ComputerPlayer(id,"��ǻ��"+id,order-1,2,StoneType.White,0.0);
								match.players[id] = p2;
								id++;
								p2.gameCount++;
								System.out.println("��ǻ�� �����Ϸ�");
								p1 = new Player(id,name,order,1,StoneType.Black,0.0);
								match.players[id] = p1;
								System.out.println("�÷��̾� �����Ϸ�");
								id++;
								p1.gameCount++;
								playerCheck = true;
								break;
							}
							else {
								System.out.println("1�Ǵ� 2 �Է�");
								playerCheck = false;
							}
						}

						if(playerCheck) {
							System.out.println("=====������ �÷��̾� �������=====");
							System.out.println("<���̵�> "+p1.getId()+"<���Ӽ���>"+p1.getOrder()+"<�̸�>"+p1.getName()+"<����Ÿ��>"+p1.getPlayerType());
							System.out.println("<���̵�> "+p2.getId()+"<���Ӽ���>"+p2.getOrder()+"<�̸�>"+p2.getName()+"<����Ÿ��>"+p2.getPlayerType());
							System.out.println("�÷��̾ ���� ������ �ڵ����� ��ǻ�Ͱ� ���� �����ϴ�.");
							while(true) {
								System.out.println("1. ������ ���");
								System.out.println("2. �����ǿ� �� ����(������ �ڵ����� ����˴ϴ�.)");
								System.out.println("3. ����");
								int start = sc.nextInt();
								if(start ==1) {
									match.showBoard();
									System.out.print("���� �ٵϵ��� ����: ");
									System.out.println(stoneNum);
								}
								else if(start == 2) {
									if(p1.getOrder() == 1) {
										System.out.println("�÷��̾��� �����Դϴ�. ���� ���� ��ġ�� �����ϼ���");
										int r1 = sc.nextInt();
										int c1= sc.nextInt();

										position = new Position(r1,c1);
										if(match.checkValidity(position)) {
											match.registerStone(r1, c1, p1.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("�̹� ���� �������ֽ��ϴ�.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p1.getName()+"�÷��̾��� �¸��Դϴ�.");
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
										
										System.out.println("��ǻ���� �����Դϴ� �ڵ����� ���� �����ϴ�.");
										position = new Position(p2.play(match.getBoard()).getRow(),p2.play(match.getBoard()).getColumn());
										if(match.checkValidity(position)) {
											match.registerStone(position.getRow(),position.getColumn(),p2.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("�̹� ���� �������ֽ��ϴ�.");
										}
										
										if(match.checkWinningCondition(position))
										{
											System.out.println(p2.getName()+"�÷��̾��� �¸��Դϴ�.");


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

										System.out.println("��ǻ���� �����Դϴ� �ڵ����� ���� �����ϴ�.");
										position = new Position(p2.play(match.getBoard()).getRow(),p2.play(match.getBoard()).getColumn());
										if(match.checkValidity(position)) {
											match.registerStone(position.getRow(), position.getColumn(),p2.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("�̹� ���� �������ֽ��ϴ�.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p2.getName()+"�÷��̾��� �¸��Դϴ�.");


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
										System.out.println("�÷��̾��� �����Դϴ�. ���� ���� ��ġ�� �����ϼ���");
										int r1 = sc.nextInt();
										int c1= sc.nextInt();

										position = new Position(r1,c1);
										if(match.checkValidity(position)) {
											match.registerStone(r1, c1, p1.getStone());
											stoneNum++;
										}
										else
										{
											System.out.println("�̹� ���� �������ֽ��ϴ�.");
										}
										if(match.checkWinningCondition(position))
										{
											System.out.println(p1.getName()+"�÷��̾��� �¸��Դϴ�.");
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
									System.out.println("1~3������ �����Է�");
								}
							}

						}
					}
					else if(chooseType == 3) {
						break;
					}
					else {
						System.out.println("1~3������ �����Է�");
					}

				}
			}
			else if(choose == 2) {
				match.setPlayType(choose);
				System.out.println("���� ���Ӹ��(1. ����,2.��Ʈ��ũ) :"+match.getPlayType());
				System.out.println("��Ʈ��ũ���� ���� �̱��� �����Դϴ�.");
			}
			else if(choose == 3) {
				match.ClearBoard();
				break;
			}
			else
			{
				System.out.println("1~3������ �����Է�");
			}

		}
		sc.close();

	}

}
