package 오목;

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
		if(playType == 1)	// 1 : 로컬
		{
			super.insertPlayers(name1, name2, selectType);
		}
		else if(playType == 2)	// 2 : 네트워크
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
				System.out.println("입력 범위 초과! (1 or 2)");
			}
		}
	}
	
	public void run()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("---------- 오목 프로그램                    ----------");
		System.out.println("---------- 바둑판 크기 설정                ----------");
		System.out.println("---------- 1. 기본 설정 (19x19) ----------");
		System.out.println("---------- 2. 임의 설정 (선택)   ----------");
		System.out.print("선택 : ");
		
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
				System.out.println("---------- 오목 게임메뉴          ----------");
				System.out.println("---------- 1. 게임 진행         ----------");
				System.out.println("---------- 2. 게임 정보         ----------");
				System.out.println("---------- 3. 게임 종료         ----------");
				System.out.print("선택 : ");

				int menu = sc.nextInt();

				switch(menu)
				{
				case 1:	// 1. 게임 진행
					while(true)
					{
						System.out.println("---------- 게임 진행           ----------");
						System.out.println("---------- 1. 대국 진행    ----------");
						System.out.println("---------- 2. 대국 현황    ----------");
						System.out.println("---------- 3. 대국 재시작 ----------");
						System.out.println("---------- 4. 대국 종료    ----------");

						int boardMenu = sc.nextInt();

						if(boardMenu == 1)
						{
							System.out.println("대국을 시작합니다.");
							System.out.println("---------- 플레이어 선택           ----------");
							System.out.println("---------- 1. 새로운 플레이어 ----------");
							System.out.println("---------- 2. 기존 플레이어    ----------");
							
							int playerMenu = sc.nextInt();
							
							if(playerMenu == 1)
							{
								System.out.println("---------- 새로운 플레이어 ----------");
								System.out.println("---------- 게임 타입 ----------");
								System.out.println("(1: 로컬, 2 : 네트워크)");
								System.out.print("선택 : ");
								int playType = sc.nextInt();
								setPlayType(playType);

								System.out.println("---------- 선수 등록 ----------");
								System.out.print("선수 1 : ");
								String name1 = sc.next();
								System.out.print("선수 2 : ");
								String name2 = sc.next();

								System.out.println("---------- 게임 순서 ----------");
								System.out.println("선수 1 (1 : 흑, 2 : 백), 선수 2 (자동 선택) ");
								System.out.print("선택 : ");
								int selectType = sc.nextInt();

								registerPlayers(playType, name1, name2, selectType);
							}
							else if(playerMenu == 2)
							{
								System.out.println("---------- 기존 플레이어 ----------");
								System.out.print("기존 ID 검색 : ");
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
				case 2:	// 2. 게임 정보
					displayMatchInfo();
					break;
				case 3:	// 3. 게임 종료
					System.exit(1);
				}
			}
		}
		else if(sizeMenu == 2)
		{			
			while(true)
			{
				System.out.println("---------- 오목판 임의 설정 ----------");
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
						System.out.println("---------- 오목 게임메뉴          ----------");
						System.out.println("---------- 1. 게임 진행         ----------");
						System.out.println("---------- 2. 게임 정보         ----------");
						System.out.println("---------- 3. 게임 종료         ----------");
						System.out.print("선택 : ");

						int menu = sc.nextInt();

						switch(menu)
						{
						case 1:	// 1. 게임 진행
							while(true)
							{
								System.out.println("---------- 게임 진행           ----------");
								System.out.println("---------- 1. 대국 진행    ----------");
								System.out.println("---------- 2. 대국 현황    ----------");
								System.out.println("---------- 3. 대국 재시작 ----------");
								System.out.println("---------- 4. 대국 종료    ----------");

								int boardMenu = sc.nextInt();

								if(boardMenu == 1)
								{
									System.out.println("대국을 시작합니다.");
									System.out.println("---------- 플레이어 선택           ----------");
									System.out.println("---------- 1. 새로운 플레이어 ----------");
									System.out.println("---------- 2. 기존 플레이어    ----------");
									
									int playerMenu = sc.nextInt();
									
									if(playerMenu == 1)
									{
										System.out.println("---------- 새로운 플레이어 ----------");
										System.out.println("---------- 게임 타입 ----------");
										System.out.println("(1: 로컬, 2 : 네트워크)");
										System.out.print("선택 : ");
										int playType = sc.nextInt();
										mm.setPlayType(playType);

										System.out.println("---------- 선수 등록 ----------");
										System.out.print("선수 1 : ");
										String name1 = sc.next();
										System.out.print("선수 2 : ");
										String name2 = sc.next();

										System.out.println("---------- 게임 순서 ----------");
										System.out.println("선수 1 (1 : 흑, 2 : 백), 선수 2 (자동 선택) ");
										System.out.print("선택 : ");
										int selectType = sc.nextInt();

										mm.registerPlayers(playType, name1, name2, selectType);
									}
									else if(playerMenu == 2)
									{
										System.out.println("---------- 기존 플레이어 ----------");
										System.out.print("기존 ID 검색 : ");
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
						case 2:	// 2. 게임 정보
							mm.displayMatchInfo();
							break;
						case 3:	// 3. 게임 종료
							System.exit(1);
						}
					}
				}
				else
				{
					System.out.println("입력 범위 초과! (0 ~ 2)");
				}
			}
		}
	}
}
