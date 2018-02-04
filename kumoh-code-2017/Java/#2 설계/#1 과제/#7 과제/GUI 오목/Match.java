package ����;

import java.util.Scanner;

public class Match
{
	protected Player[] players = new Player[3];	// �÷��̾���� �迭. setPlayer �޼ҵ带 ���� �����
	protected int turn;	// ���� �÷��̾� ��ȣ. 1���̸� ù ��° �÷��̾�, 2�̸� �� ��° �÷��̾�
	protected int order;
	protected int playType;	// ���� Ÿ�� (1 : ����, 2 : ��Ʈ��ũ)
	protected OmokBoard playBoard;	// ���ӿ� ���Ǵ� �ٵ��� ��ü
	protected int boardSize;	// 0�̸� 10x10, 1�̸� 15x15, 2�̸� 19x19
	// ���� ���и� ������ �� �ִ����� �Ǵ��Ͽ� �Ǵ� ������ ���� true�� ��ȯ�ϰ� �׷��� ������ false�� ��ȯ
	protected boolean checkWinningCondition(Position p)
	{
		int[] stoneNum = new int[8];
		
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
		turn = 1;
		order = 0;
	}
	
	public Match(int rows, int cols)
	{
		playBoard = new OmokBoard(rows, cols);
		players = new Player[3];
		turn = 1;
		order = 0;
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
	public StoneType getCurrentColor()
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
	
	public void insertPlayers(String name1, String name2)
	{
		players[1] = new Player(1, name1, 1, 100);
		players[2] = new Player(2, name2, 2, 100);
	}
	
	public void insertStone(int x, int y, StoneType stone)
	{
		playBoard.putStone(x, y, stone);
	}
}
