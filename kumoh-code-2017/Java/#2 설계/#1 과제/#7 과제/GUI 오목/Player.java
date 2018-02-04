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
	
	public Player() {}	// �⺻ ������
	// ������ ����� �ʱ�ȭ
	public Player(int id, String name, int order, double winningRate)
	{
		this.id = id;
		this.name = name;
		this.order = order;
		this.winningRate = winningRate;
	}
	
	public int getId() {return id;}	// id�� ��ȯ
	public int getOrder() {return order;}	// order�� ��ȯ
	public int getPlayerType() {return playerType;}	// playerType�� ��ȯ
	public String getName() {return name;}	// name�� ��ȯ
	
	public Position play(OmokBoard board)
	{
		if(id == 1)
		{
			System.out.println("[player1]");
		}
		else
		{
			System.out.println("[player2]");	
		}
		System.out.println(name + "�� ���� �� ��ġ�� �Է��ϼ���");
		Scanner sc = new Scanner(System.in);
		System.out.print("(x y) : ");
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		Position p = new Position(x,y);
		return p;
	}
}
