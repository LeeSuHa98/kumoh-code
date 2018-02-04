package 오목;

import java.util.Scanner;

public class Player
{
	protected int id;	// 사용자 id
	protected String name;	// 플레이어 이름
	protected int order;	// 게임순서 (1 또는 2)
	protected int playerType;	// 플레이어 타입 (1 : 사람, 2 : 사이버)
	protected double winningRate;	// 승률
	protected StoneType stoneType;
	protected int winningCount;	// 경기를 이긴 횟수
	protected int gameCount;	// 게임 횟수
	
	public Player() {}	// 기본 생성자
	// 데이터 멤버를 초기화
	public Player(int id, String name, int order, int playerType, double winningRate, StoneType stoneType)
	{
		this.id = id;
		this.name = name;
		this.order = order;
		this.playerType = playerType;
		this.winningRate = winningRate;
		this.stoneType = stoneType;
		winningCount = 0;
		gameCount = 0;
	}
	
	public int getId() {return id;}	// id를 반환
	public int getOrder() {return order;}	// order를 반환
	public int getPlayerType() {return playerType;}	// playerType를 반환
	public double getWinningRate() {return winningRate;}	// winningRate를 반환
	public int getWinningCount() {return winningCount;}
	public int getGameCount() {return gameCount;}
	public String getName() {return name;}	// name을 반환
	
	public void setWinningRate(double winningRate) {this.winningRate = winningRate;}
	
	public void plusWinningCount() {winningCount++;}
	public void plusGameCount() {gameCount++;}
}
