package ����;

public class Computer extends Player
{
	public Computer() {}	// �⺻ ������
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
