package 오목;

public class Computer extends Player
{
	public Computer() {}	// 기본 생성자
	public Computer(int id, String name, int order, int playerType, int winningRate, StoneType stoneType)
	{
		this.id = id;
		this.name = name;
		this.order = order;
		this.playerType = playerType;
		this.winningRate = winningRate;
		this.stoneType = stoneType;
	}
}
