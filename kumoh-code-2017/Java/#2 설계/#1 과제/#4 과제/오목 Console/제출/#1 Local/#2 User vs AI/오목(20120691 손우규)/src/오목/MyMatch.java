package ����;

import java.util.Scanner;

public class MyMatch extends Match
{	
	public MyMatch() {}
	public MyMatch(int rows, int cols)
	{
		super(rows, cols);
	}

	public boolean getCheckWinningCondition(Position p)
	{
		return checkWinningCondition(p);
	}
	
	public boolean getCheckValidity(Position p)
	{
		return checkValidity(p);
	}
	
	public void registerPlayers(int playType, String name1, String name2, int selectType)
	{
		if(playType == 1)	// 1 : ����
		{
			super.insertPlayers(name1, name2, selectType);
		}
		else if(playType == 2)	// 2 : ��Ʈ��ũ
		{
			if(selectType == 1)
			{
				Player p = new Player(1, name1, 1, 1, 100, StoneType.Black);
				ComputerPlayer c = new ComputerPlayer(2, "computer", 2, 2, 100, StoneType.White);
				setPlayers(p, c);
				movePlay(turn, p, c);
			}
			else if(selectType == 2)
			{
				ComputerPlayer c = new ComputerPlayer(1, "computer", 1, 2, 100, StoneType.Black);
				Player p = new Player(2, name2, 2, 1, 100, StoneType.White);
				setPlayers(c, p);
				movePlay(turn, p, c);
			}
			else
			{
				System.out.println("�Է� ���� �ʰ�! (1 or 2)");
			}
		}
	}
	
	public void run()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("---------- ���� ���α׷�                    ----------");
		System.out.println("---------- �ٵ��� ũ�� ����                ----------");
		System.out.println("---------- 1. �⺻ ���� (19x19) ----------");
		System.out.println("---------- 2. ���� ���� (����)   ----------");
		System.out.print("���� : ");
		
		int sizeMenu = sc.nextInt();
		
		play(sizeMenu);
	}
	
	public void play(int sizeMenu)
	{
		Scanner sc = new Scanner(System.in);

		if(sizeMenu == 1)
		{
			while(true)
			{
				System.out.println("---------- ���� ���Ӹ޴�          ----------");
				System.out.println("---------- 1. ���� ����         ----------");
				System.out.println("---------- 2. ���� ����         ----------");
				System.out.println("---------- 3. ���� ����         ----------");
				System.out.print("���� : ");

				int menu = sc.nextInt();

				switch(menu)
				{
				case 1:	// 1. ���� ����
					while(true)
					{
						System.out.println("---------- ���� ����           ----------");
						System.out.println("---------- 1. �뱹 ����    ----------");
						System.out.println("---------- 2. �뱹 ��Ȳ    ----------");
						System.out.println("---------- 3. �뱹 ����� ----------");
						System.out.println("---------- 4. �뱹 ����    ----------");

						int boardMenu = sc.nextInt();

						if(boardMenu == 1)
						{
							System.out.println("�뱹�� �����մϴ�.");
							System.out.println("---------- �÷��̾� ����           ----------");
							System.out.println("---------- 1. ���ο� �÷��̾� ----------");
							System.out.println("---------- 2. ���� �÷��̾�    ----------");
							
							int playerMenu = sc.nextInt();
							
							if(playerMenu == 1)
							{
								System.out.println("---------- ���ο� �÷��̾� ----------");
								System.out.println("---------- ���� Ÿ�� ----------");
								System.out.println("(1: ����, 2 : ��Ʈ��ũ)");
								System.out.print("���� : ");
								int playType = sc.nextInt();
								setPlayType(playType);

								System.out.println("---------- ���� ��� ----------");
								System.out.print("���� 1 : ");
								String name1 = sc.next();
								System.out.print("���� 2 : ");
								String name2 = sc.next();

								System.out.println("---------- ���� ���� ----------");
								System.out.println("���� 1 (1 : ��, 2 : ��), ���� 2 (�ڵ� ����) ");
								System.out.print("���� : ");
								int selectType = sc.nextInt();

								registerPlayers(playType, name1, name2, selectType);
							}
							else if(playerMenu == 2)
							{
								System.out.println("---------- ���� �÷��̾� ----------");
								System.out.print("���� ID �˻� : ");
								int indexId = sc.nextInt();
								
								findPlayers(indexId);
							}
						}
						else if(boardMenu == 2)
						{
							displayBoard();
							displayMatch();
						}
						else if(boardMenu == 3)
						{
							resetMatch();
						}
						else
						{
							break;
						}
					}
					break;
				case 2:	// 2. ���� ����
					displayMatchInfo();
					break;
				case 3:	// 3. ���� ����
					System.exit(1);
				}
			}
		}
		else if(sizeMenu == 2)
		{			
			while(true)
			{
				System.out.println("---------- ������ ���� ���� ----------");
				System.out.println("---------- 0 : 10 x 10 ----------");
				System.out.println("---------- 1 : 15 x 15 ----------");
				System.out.println("---------- 2 : 19 x 19 ----------");
				int size = sc.nextInt();
				
				if(size >= 0 || size < 3) 
				{
					setBoard(size);
					MyMatch mm = new MyMatch(getBoard(), getBoard());
					while(true)
					{
						System.out.println("---------- ���� ���Ӹ޴�          ----------");
						System.out.println("---------- 1. ���� ����         ----------");
						System.out.println("---------- 2. ���� ����         ----------");
						System.out.println("---------- 3. ���� ����         ----------");
						System.out.print("���� : ");

						int menu = sc.nextInt();

						switch(menu)
						{
						case 1:	// 1. ���� ����
							while(true)
							{
								System.out.println("---------- ���� ����           ----------");
								System.out.println("---------- 1. �뱹 ����    ----------");
								System.out.println("---------- 2. �뱹 ��Ȳ    ----------");
								System.out.println("---------- 3. �뱹 ����� ----------");
								System.out.println("---------- 4. �뱹 ����    ----------");

								int boardMenu = sc.nextInt();

								if(boardMenu == 1)
								{
									System.out.println("�뱹�� �����մϴ�.");
									System.out.println("---------- �÷��̾� ����           ----------");
									System.out.println("---------- 1. ���ο� �÷��̾� ----------");
									System.out.println("---------- 2. ���� �÷��̾�    ----------");
									
									int playerMenu = sc.nextInt();
									
									if(playerMenu == 1)
									{
										System.out.println("---------- ���ο� �÷��̾� ----------");
										System.out.println("---------- ���� Ÿ�� ----------");
										System.out.println("(1: ����, 2 : ��Ʈ��ũ)");
										System.out.print("���� : ");
										int playType = sc.nextInt();
										mm.setPlayType(playType);

										System.out.println("---------- ���� ��� ----------");
										System.out.print("���� 1 : ");
										String name1 = sc.next();
										System.out.print("���� 2 : ");
										String name2 = sc.next();

										System.out.println("---------- ���� ���� ----------");
										System.out.println("���� 1 (1 : ��, 2 : ��), ���� 2 (�ڵ� ����) ");
										System.out.print("���� : ");
										int selectType = sc.nextInt();

										mm.registerPlayers(playType, name1, name2, selectType);
									}
									else if(playerMenu == 2)
									{
										System.out.println("---------- ���� �÷��̾� ----------");
										System.out.print("���� ID �˻� : ");
										int indexId = sc.nextInt();
										
										mm.findPlayers(indexId);
									}
								}
								else if(boardMenu == 2)
								{
									mm.displayBoard();
									mm.displayMatch();
								}
								else if(boardMenu == 3)
								{
									mm.resetMatch();
								}
								else
								{
									break;
								}
							}
							break;
						case 2:	// 2. ���� ����
							mm.displayMatchInfo();
							break;
						case 3:	// 3. ���� ����
							System.exit(1);
						}
					}
				}
				else
				{
					System.out.println("�Է� ���� �ʰ�! (0 ~ 2)");
				}
			}
		}
	}
}
