package ����;

import java.util.Scanner;

public class Match
{
	protected Player[] players;	// �÷��̾���� �迭. setPlayer �޼ҵ带 ���� �����
	protected int turn;	// ���� �÷��̾� ��ȣ. 1���̸� ù ��° �÷��̾�, 2�̸� �� ��° �÷��̾�
	protected int playType;	// ���� Ÿ�� (1 : ����, 2 : ��Ʈ��ũ)
	protected OmokBoard playBoard;	// ���ӿ� ���Ǵ� �ٵ��� ��ü
	protected int boardSize;	// 0�̸� 10x10, 1�̸� 15x15, 2�̸� 19x19
	private int stoneCount;	// ���� ���� Ƚ��
	// ���� ���и� ������ �� �ִ����� �Ǵ��Ͽ� �Ǵ� ������ ���� true�� ��ȯ�ϰ� �׷��� ������ false�� ��ȯ
	protected boolean checkWinningCondition(Position p)
	{
		int[] stoneNum = new int[10];
		
		playBoard.countSameColorStones(p, playBoard.getStone(p.getRow(), p.getColumn()), stoneNum);
		// ���� 5�� �̻��� �� ���
		if(stoneNum[0] + stoneNum[4] >= 4 || stoneNum[1] + stoneNum[5] >= 4 || stoneNum[2] + stoneNum[6] >= 4 || stoneNum[3] + stoneNum[7] >= 4)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	// Position p�� ��ȿ�� ������, �� ���� ���� �� �ִ� �ڸ����� �˻��Ͽ� �� ����� �� �Ǵ� �������� ��ȯ
	protected boolean checkValidity(Position p)
	{
		if(playBoard.getStone(p.getRow(), p.getColumn()) == StoneType.None)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public Match()
	{
		playBoard = new OmokBoard();
		players = new Player[3];
		Player p = new Player();
		turn = p.getOrder();
		stoneCount = 1;
	}
	
	public Match(int rows, int cols)
	{
		playBoard = new OmokBoard(rows, cols);
		players = new Player[3];
		Player p = new Player();
		turn = p.getOrder();
		stoneCount = 1;
	}
	
	public int getTurn() {return turn;}	// ���� �� ��° �������� ��ȯ
	public void setTurn(int turn) {this.turn = turn;}	// �� ������ n���� ����
	public Player getPlayer(int n) {return players[n];}	// n ��° �÷��̾ ��ȯ
	// n��° �÷��̾ player�� ����
	public void setPlayer(int n, Player p)
	{
		players[n] = p;
	}
	public void setPlayers(Player p1, Player p2) 
	{
		players[1] = p1;
		players[2] = p2;
	}
	public Player getCurrentPlayer(int turn) {return players[turn];}	// ���� �÷��̾ ��ȯ
	// �� ������ �� ���� ��ȯ
	public StoneType getCurrentColor(int turn)
	{
		if(turn == 1)
		{
			return StoneType.Black;
		}
		else if(turn == 2)
		{
			return StoneType.White;
		}
		else
		{
			return StoneType.None;
		}
	}
	public int getBoard() {return boardSize;}
	public void setBoard(int n) 
	{
		if(n == 0) 
		{
			boardSize = 10;
		}
		else if(n == 1) 
		{
			boardSize = 15;
		}
		else if(n == 2) 
		{
			boardSize = 19;
		}
		else
		{
			System.out.println("�Է� ���� �ʰ�! (1 or 2)");
		}
	}
	public int getPlayType() {return playType;}	// playType �� ��ȯ
	public void setPlayType(int n) {this.playType = n;}	// playType ���� n���� ����
	
	public void movePlay(int stoneCount, Player p1, Player p2)
	{
		Scanner sc = new Scanner(System.in);
		
		p1.plusGameCount();	// �÷��̾� 1 ��� Ƚ��
		p2.plusGameCount();	// �÷��̾� 2 ��� Ƚ��
		
		while(true)
		{
			playBoard.printBoard();
			
			if(stoneCount % 2 != 0)
			{
				System.out.println(p1.getOrder() + "��° �÷��̾��� �����Դϴ�.");
				System.out.println("------ [player " + p1.getId() + "] ------");
				System.out.println("��� Ƚ�� : " + p1.getGameCount());
				System.out.println("�¸� Ƚ�� : " + p1.getWinningCount());
				System.out.println("�·� : " + p1.getWinningRate());

				System.out.print("���� ��ġ x : ");
				int row = sc.nextInt();
				System.out.print("���� ��ġ y : ");
				int column = sc.nextInt();
				
				if(row == 999 || column == 999)	// ���� �ߴ�
				{
					break;
				}

				Position position = new Position(row, column);
				if(checkValidity(position)) 
				{
					insertStone(row, column, StoneType.Black);
					stoneCount++;
				}
				else
				{
					System.out.println("�̹� ���� �������ֽ��ϴ�.");
				}
				if(checkWinningCondition(position))
				{
					p1.plusWinningCount();
					p1.setWinningRate((p1.getWinningCount() * 100) / p1.getGameCount());
					System.out.println(p1.getOrder() + "��° �÷��̾��� �¸�!");
					System.out.println("���� �÷��̾��� �·� : " + p1.getWinningRate());
					System.out.println("���� �÷��̾��� �¸� Ƚ�� : " + p1.getWinningCount());
					break;
				}
			}
			else
			{
				System.out.println(p2.getOrder() + "��° �÷��̾��� �����Դϴ�.");
				System.out.println("------ [player " + p2.getId() + "] ------");
				System.out.println("��� Ƚ�� : " + p2.getGameCount());
				System.out.println("�¸� Ƚ�� : " + p2.getWinningCount());
				System.out.println("�·� : " + p2.getWinningRate());

				System.out.print("���� ��ġ x : ");
				int row = sc.nextInt();
				System.out.print("���� ��ġ y : ");
				int column = sc.nextInt();

				if(row == 999 || column == 999)	// ���� �ߴ�
				{
					break;
				}
				Position position = new Position(row, column);
				if(checkValidity(position)) 
				{
					insertStone(row, column, StoneType.White);
					stoneCount++;
				}
				else 
				{
					System.out.println("�̹� ���� ������ �ֽ��ϴ�.");
				}
				if(checkWinningCondition(position))
				{
					p2.plusWinningCount();
					p2.setWinningRate((p2.getWinningCount() * 100) / p2.getGameCount());
					System.out.println(p2.getOrder() + "��° �÷��̾��� �¸�!");
					System.out.println("�·� : "+ p2.getWinningRate());
					System.out.println("�¸� Ƚ�� : "+ p2.getWinningCount());
					break;
				}
			}
		}
	}
	
	public void resetMatch()
	{
		System.out.println("---------- ���� �ʱ�ȭ ----------");
		playBoard.clear();
	}
	
	public void displayMatchInfo()
	{
		System.out.println("---------- ���� ���� ----------");
		System.out.println("������ : 10x10, 15x15, 19x19");
		System.out.println("���� ��Ģ : �׻� ����� �����ϸ�, ���� 33 ���� (���߿� ����)");
		System.out.println("���� : �÷��̾� vs �÷��̾�");
		System.out.println("��Ʈ��ũ : �÷��̾� vs ��ǻ��");
	}
	
	public void displayMatch()
	{
		Scanner sc = new Scanner(System.in);
		Player p1 = players[1];
		Player p2 = players[2];
		System.out.println("---------- ���� ��Ȳ�� ----------");
		System.out.println("---------- 1. ���� 1 ----------");
		System.out.println("---------- 2. ���� 2 ----------");
		
		int select = sc.nextInt();
		
		if(select == p1.getId())
		{
			System.out.println("��� : " + p1.getPlayerType());
			System.out.println("���� �÷��̾� : " + getCurrentPlayer(p1.getOrder()));
			System.out.println("�÷��̾� Ÿ�� (1: ���, 2 : ���̹�): " + p1.getPlayerType());
			System.out.println("���Ӽ��� (1 �Ǵ� 2) : " + p1.getOrder());
			System.out.println("�� ���� : " + getCurrentColor(p1.getOrder()));
			System.out.println("��� Ƚ�� : " + p1.getGameCount());
			System.out.println("�¸� Ƚ�� : " + p1.getWinningCount());
			System.out.println("�·� : " + p1.getWinningRate());
		}
		else if(select == p2.getId())
		{
			System.out.println("��� : " + p2.getPlayerType());
			System.out.println("���� �÷��̾� : " + getCurrentPlayer(p2.getOrder()));
			System.out.println("�÷��̾� Ÿ�� (1: ���, 2 : ���̹�): " + p2.getPlayerType());
			System.out.println("���Ӽ��� (1 �Ǵ� 2) : " + p2.getOrder());
			System.out.println("�� ���� : " + getCurrentColor(p2.getOrder()));
			System.out.println("��� Ƚ�� : " + p2.getGameCount());
			System.out.println("�¸� Ƚ�� : " + p2.getWinningCount());
			System.out.println("�·� : " + p2.getWinningRate());
		}
	}
	
	public void displayBoard()
	{
		playBoard.printBoard();
	}
	
	public void findPlayers(int indexId)
	{
		Player p1 = players[1];
		Player p2 = players[2];
		
		for(int i = 1; i < 3; i++) 
		{
			if(players[i].getId() == indexId ) 
			{			
				int findId = i;
				System.out.println("�˻� �Ϸ�");

				if(findId == p1.getId())	// ���� �÷��̾� �˻�
				{
					p1 = new Player(players[findId].getId(), players[findId].getName(), 1, players[findId].getPlayerType(), players[findId].getWinningRate(),StoneType.Black);
					setPlayer(findId, p2);
					movePlay(stoneCount, p1, p2);
				}
				else if(findId == p2.getId())
				{
					p2 = new Player(players[findId].getId(), players[findId].getName(), 2, players[findId].getPlayerType(), players[findId].getWinningRate(),StoneType.White);
					setPlayer(findId, p1);
					movePlay(stoneCount, p1, p2);
				}
			}
			else
			{
				System.out.println("���� �÷��̾ �������� �ʽ��ϴ�!");
			}
		}
	}
	
	public void insertPlayers(String name1, String name2, int selectType)
	{
		if(selectType == 1)
		{
			Player p1 = new Player(1, name1, 1, 1, 0, StoneType.Black);
			Player p2 = new Player(2, name2, 2, 1, 0, StoneType.White);
			setPlayers(p1, p2);
			movePlay(stoneCount, p1, p2);
		}
		else if(selectType == 2)
		{
			Player p1 = new Player(1, name1, 2, 1, 0, StoneType.White);
			Player p2 = new Player(2, name2, 1, 1, 0, StoneType.Black);
			setPlayers(p1, p2);
			movePlay(stoneCount, p2, p1);
		}
		else
		{
			System.out.println("�Է� ���� �ʰ�! (1 or 2)");
		}
	}
	
	public void insertStone(int x, int y, StoneType stone)
	{
		playBoard.putStone(x, y, stone);
	}
}
