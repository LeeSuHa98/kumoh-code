package 오목;

import java.util.Scanner;

public class Match
{
	protected Player[] players = new Player[3];	// 플레이어들의 배열. setPlayer 메소드를 통해 저장됨
	protected int turn;	// 현재 플레이어 번호. 1번이면 첫 번째 플레이어, 2이면 두 번째 플레이어
	protected int order;
	protected int playType;	// 게임 타입 (1 : 로컬, 2 : 네트워크)
	protected OmokBoard playBoard;	// 게임에 사용되는 바둑판 객체
	protected int boardSize;	// 0이면 10x10, 1이면 15x15, 2이면 19x19
	// 게임 승패를 결정할 수 있는지를 판단하여 판단 가능한 경우는 true를 반환하고 그렇지 않으면 false를 반환
	protected boolean checkWinningCondition(Position p)
	{
		int[] stoneNum = new int[8];
		
		playBoard.countSameColorStones(p, playBoard.getStone(p.getRow(), p.getColumn()), stoneNum);
		// 돌이 5개 이상이 될 경우
		if(stoneNum[0] + stoneNum[4] >= 4 || stoneNum[1] + stoneNum[5] >= 4 || stoneNum[2] + stoneNum[6] >= 4 || stoneNum[3] + stoneNum[7] >= 4)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	// Position p가 유효한 것인지, 즉 돌을 놓을 수 있는 자리인지 검사하여 그 결과를 참 또는 거짓으로 반환
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
	
	public int getTurn() {return turn;}	// 현재 몇 번째 순서인지 반환
	public void setTurn(int turn) {this.turn = turn;}	// 현 순서를 n으로 지정
	public Player getPlayer(int n) {return players[n];}	// n 번째 플레이어를 반환
	// n번째 플레이어를 player로 지정
	public void setPlayer(int n, Player p)
	{
		players[n] = p;
	}
	public void setPlayers(Player p1, Player p2) 
	{
		players[1] = p1;
		players[2] = p2;
	}
	public Player getCurrentPlayer(int turn) {return players[turn];}	// 현재 플레이어를 반환
	// 현 주자의 돌 색깔 반환
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
			System.out.println("입력 범위 초과! (1 or 2)");
		}
	}
	public int getPlayType() {return playType;}	// playType 값 반환
	public void setPlayType(int n) {this.playType = n;}	// playType 값을 n으로 지정
	
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
