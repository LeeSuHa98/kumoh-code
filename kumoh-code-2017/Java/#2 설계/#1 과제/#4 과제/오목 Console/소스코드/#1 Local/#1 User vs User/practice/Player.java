package practice;

public class Player {

	private int id;
	private int order;
	private int playerType;
	private double winningRate;
	private int gameCount=0;
	private int winCount=0;
	private String name;
	private StoneType s;
	
	public Player(int id,String name,int order,int playerType,StoneType s) {
		this.id = id;
		this.name = name;
		this.order = order; // 순서
		this.playerType = playerType; // 1이면사람 2이면 컴퓨터
		this.s = s;
		gameCount++;//생성자 생성시 게임횟수 1 증가
	}
	
	public Player() {
	}

	public int getId() {
		return id;
	}
	public int getOrder() {
		return order;
	}
	public int getPlayerType() {
		return playerType;
	}
	public String getName() {
		return name;
	}
	public void setWinningRate() {
		winCount = winCount+1;
		winningRate = winCount/gameCount;
	}
	public double getWinningRate() {
		return winningRate;
	}
	public StoneType getStone() {
		return s;
	}
	
}
