package ����;

import java.util.Scanner;

public class Player
{
	protected int id;	// ����� id
	protected String name;	// �÷��̾� �̸�
	protected int order;	// ���Ӽ��� (1 �Ǵ� 2)
	protected int playerType;	// �÷��̾� Ÿ�� (1 : ���, 2 : ���̹�)
	protected double winningRate;	// �·�
	protected StoneType stoneType;
	protected int winningCount;	// ��⸦ �̱� Ƚ��
	protected int gameCount;	// ���� Ƚ��
	
	public Player() {}	// �⺻ ������
	// ������ ����� �ʱ�ȭ
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
	
	public int getId() {return id;}	// id�� ��ȯ
	public int getOrder() {return order;}	// order�� ��ȯ
	public int getPlayerType() {return playerType;}	// playerType�� ��ȯ
	public double getWinningRate() {return winningRate;}	// winningRate�� ��ȯ
	public int getWinningCount() {return winningCount;}
	public int getGameCount() {return gameCount;}
	public String getName() {return name;}	// name�� ��ȯ
	
	public void setWinningRate(double winningRate) {this.winningRate = winningRate;}
	
	public void plusWinningCount() {winningCount++;}
	public void plusGameCount() {gameCount++;}
}
