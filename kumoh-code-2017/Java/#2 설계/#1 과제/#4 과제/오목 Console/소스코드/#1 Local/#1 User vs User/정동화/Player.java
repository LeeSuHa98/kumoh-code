
public class Player {

	private int id;
	private int order;
	private int playerType;
	protected double winningRate;
	protected int gameCount=0; // 플레이어를 생성하는 즉시 게임이 실행되므로 1로 초기화
	protected int winCount=0;
	private String name;
	private StoneType s;
	
	public Player(int id,String name,int order,int playerType,StoneType s,double winningRate) {
		this.id = id;
		this.name = name;
		this.order = order; // 순서
		this.playerType = playerType; // 1이면사람 2이면 컴퓨터
		this.s = s;
		this.winningRate = winningRate;
	}
	
	public Player() {
		id = -999;
		gameCount = 0;
		name = null;
	}

	
	public int getGameCount() {
		return gameCount;
	}
	public int getWinCount() {
		return winCount;
	}
	public void setWinCount(int winCount) {
		this.winCount = winCount;
	}
	public void setGameCount(int gameCount) {
		this.gameCount = gameCount;
	}
	public void addWinCount() {
		setWinCount(getWinCount()+1);
	}
	public void addGameCount() {
		setGameCount(getGameCount()+1);
	}
	public int getId() {
		return id;
	}
	public int getOrder() {
		return order;
	}
	public void setOrder(int order) {
		this.order = order;
	}
	public int getPlayerType() {
		return playerType;
	}
	public String getName() {
		return name;
	}
	public double getWinningRate() {
		return winningRate;
	}
	public void setWinningRate(double winningRate) {
		this.winningRate = winningRate;
	}
	public StoneType getStone() {
		return s;
	}

	
	
}
