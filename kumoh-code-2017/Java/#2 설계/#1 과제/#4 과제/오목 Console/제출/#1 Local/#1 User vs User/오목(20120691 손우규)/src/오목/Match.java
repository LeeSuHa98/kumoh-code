package 오목;

import java.util.Scanner;

public class Match
{
	protected Player[] players;	// 플레이어들의 배열. setPlayer 메소드를 통해 저장됨
	protected int turn;	// 현재 플레이어 번호. 1번이면 첫 번째 플레이어, 2이면 두 번째 플레이어
	protected int playType;	// 게임 타입 (1 : 로컬, 2 : 네트워크)
	protected OmokBoard playBoard;	// 게임에 사용되는 바둑판 객체
	protected int boardSize;	// 0이면 10x10, 1이면 15x15, 2이면 19x19
	private int stoneCount;	// 돌을 놓는 횟수
	// 게임 승패를 결정할 수 있는지를 판단하여 판단 가능한 경우는 true를 반환하고 그렇지 않으면 false를 반환
	protected boolean checkWinningCondition(Position p)
	{
		int[] stoneNum = new int[10];
		
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
			System.out.println("입력 범위 초과! (1 or 2)");
		}
	}
	public int getPlayType() {return playType;}	// playType 값 반환
	public void setPlayType(int n) {this.playType = n;}	// playType 값을 n으로 지정
	
	public void movePlay(int stoneCount, Player p1, Player p2)
	{
		Scanner sc = new Scanner(System.in);
		
		p1.plusGameCount();	// 플레이어 1 경기 횟수
		p2.plusGameCount();	// 플레이어 2 경기 횟수
		
		while(true)
		{
			playBoard.printBoard();
			
			if(stoneCount % 2 != 0)
			{
				System.out.println(p1.getOrder() + "번째 플레이어의 차례입니다.");
				System.out.println("------ [player " + p1.getId() + "] ------");
				System.out.println("경기 횟수 : " + p1.getGameCount());
				System.out.println("승리 횟수 : " + p1.getWinningCount());
				System.out.println("승률 : " + p1.getWinningRate());

				System.out.print("착수 위치 x : ");
				int row = sc.nextInt();
				System.out.print("착수 위치 y : ");
				int column = sc.nextInt();
				
				if(row == 999 || column == 999)	// 게임 중단
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
					System.out.println("이미 돌이 놓여져있습니다.");
				}
				if(checkWinningCondition(position))
				{
					p1.plusWinningCount();
					p1.setWinningRate((p1.getWinningCount() * 100) / p1.getGameCount());
					System.out.println(p1.getOrder() + "번째 플레이어의 승리!");
					System.out.println("현재 플레이어의 승률 : " + p1.getWinningRate());
					System.out.println("현재 플레이어의 승리 횟수 : " + p1.getWinningCount());
					break;
				}
			}
			else
			{
				System.out.println(p2.getOrder() + "번째 플레이어의 차례입니다.");
				System.out.println("------ [player " + p2.getId() + "] ------");
				System.out.println("경기 횟수 : " + p2.getGameCount());
				System.out.println("승리 횟수 : " + p2.getWinningCount());
				System.out.println("승률 : " + p2.getWinningRate());

				System.out.print("착수 위치 x : ");
				int row = sc.nextInt();
				System.out.print("착수 위치 y : ");
				int column = sc.nextInt();

				if(row == 999 || column == 999)	// 게임 중단
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
					System.out.println("이미 돌이 놓여져 있습니다.");
				}
				if(checkWinningCondition(position))
				{
					p2.plusWinningCount();
					p2.setWinningRate((p2.getWinningCount() * 100) / p2.getGameCount());
					System.out.println(p2.getOrder() + "번째 플레이어의 승리!");
					System.out.println("승률 : "+ p2.getWinningRate());
					System.out.println("승리 횟수 : "+ p2.getWinningCount());
					break;
				}
			}
		}
	}
	
	public void resetMatch()
	{
		System.out.println("---------- 게임 초기화 ----------");
		playBoard.clear();
	}
	
	public void displayMatchInfo()
	{
		System.out.println("---------- 게임 정보 ----------");
		System.out.println("오목판 : 10x10, 15x15, 19x19");
		System.out.println("게임 규칙 : 항상 흑부터 시작하며, 흑은 33 금지 (나중에 구현)");
		System.out.println("로컬 : 플레이어 vs 플레이어");
		System.out.println("네트워크 : 플레이어 vs 컴퓨터");
	}
	
	public void displayMatch()
	{
		Scanner sc = new Scanner(System.in);
		Player p1 = players[1];
		Player p2 = players[2];
		System.out.println("---------- 게임 현황판 ----------");
		System.out.println("---------- 1. 선수 1 ----------");
		System.out.println("---------- 2. 선수 2 ----------");
		
		int select = sc.nextInt();
		
		if(select == p1.getId())
		{
			System.out.println("모드 : " + p1.getPlayerType());
			System.out.println("현재 플레이어 : " + getCurrentPlayer(p1.getOrder()));
			System.out.println("플레이어 타입 (1: 사람, 2 : 사이버): " + p1.getPlayerType());
			System.out.println("게임순서 (1 또는 2) : " + p1.getOrder());
			System.out.println("돌 색깔 : " + getCurrentColor(p1.getOrder()));
			System.out.println("경기 횟수 : " + p1.getGameCount());
			System.out.println("승리 횟수 : " + p1.getWinningCount());
			System.out.println("승률 : " + p1.getWinningRate());
		}
		else if(select == p2.getId())
		{
			System.out.println("모드 : " + p2.getPlayerType());
			System.out.println("현재 플레이어 : " + getCurrentPlayer(p2.getOrder()));
			System.out.println("플레이어 타입 (1: 사람, 2 : 사이버): " + p2.getPlayerType());
			System.out.println("게임순서 (1 또는 2) : " + p2.getOrder());
			System.out.println("돌 색깔 : " + getCurrentColor(p2.getOrder()));
			System.out.println("경기 횟수 : " + p2.getGameCount());
			System.out.println("승리 횟수 : " + p2.getWinningCount());
			System.out.println("승률 : " + p2.getWinningRate());
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
				System.out.println("검색 완료");

				if(findId == p1.getId())	// 기존 플레이어 검색
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
				System.out.println("현재 플레이어가 존재하지 않습니다!");
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
			System.out.println("입력 범위 초과! (1 or 2)");
		}
	}
	
	public void insertStone(int x, int y, StoneType stone)
	{
		playBoard.putStone(x, y, stone);
	}
}
