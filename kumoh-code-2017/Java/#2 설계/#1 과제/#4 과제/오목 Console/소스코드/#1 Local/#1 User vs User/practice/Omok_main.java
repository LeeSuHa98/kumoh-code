package practice;

import java.util.Scanner;

public class Omok_main {

	@SuppressWarnings("unused")
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StoneType s1 = null;
		StoneType s2 = null;
		Match match = new Match();
		Player p1 = new Player();
		Player p2 = new Player();
		Position position = null;
		int id = 0;
		boolean playerCheck = false;
		int count = 1; //��������Ƚ��
		
		while(true) {
			System.out.println("==���� Ÿ�Լ��� ==");
			System.out.println("1. ���ð��� ����");
			System.out.println("2. ��Ʈ��ũ���� ����");
			System.out.println("3. ����");
			int choose = sc.nextInt();
			if(choose == 1) {
				match.setPlayType(choose);
				System.out.println("���� ���Ӹ��(1. ����,2.��Ʈ��ũ) :"+match.getPlayType());
				System.out.println("�ٵ����� ũ�⼳�� 0=10*10,1=15*15,2=19*19");
				int size = sc.nextInt();
				match.setBoardSize(size);
				match = new Match(match.getBoardSize(),match.getBoardSize());
				
				
				System.out.println("1��° �÷����� �̸����� : ");
				String name = sc.next();
				System.out.println("2��° �÷��̾� �̸�����: ");
				String name1 = sc.next();
				
				System.out.println("1��° �÷��̾��� �� ���� 1.�浹 2.�鵹(2��° �÷��̾�� �ڵ����� �����˴ϴ�.)");
				int chooseStone = sc.nextInt();
				
				if(chooseStone == 1) {
					s1 = StoneType.Black;
					s2 = StoneType.White;
					p1 = new Player(id,name,1,1,s1);
					id++;
					p2 = new Player(id,name1,2,1,s2);
					playerCheck = true;
				}
				else if(chooseStone == 2) {
					s1 = StoneType.White;
					s2 = StoneType.Black;
					p1 = new Player(id,name,1,1,s1);
					id++;
					p2 = new Player(id,name,2,1,s2);
					playerCheck = true;
				}
				else
				{
					System.out.println("1�Ǵ� 2 �Է�");
				}
				if(playerCheck) {
					while(true) {
						System.out.println("1. ������ ���");
						System.out.println("2. �����ǿ� �� ����(������ �ڵ����� ����˴ϴ�.)");
						System.out.println("3. ����");
						int start = sc.nextInt();
						if(start == 1) {
							match.showBoard();
							System.out.print("���� �ٵϵ��� ����: ");
							System.out.println(count-1);
						}
						else if(start == 2) {
							if(count %2 != 0) {
								System.out.println("1��° �÷��̾��� �����Դϴ�. ���ϴ� ��ġ�� �����ϼ���");
								int r = sc.nextInt();
								int c = sc.nextInt();
								position = new Position(r,c);
								if(match.checkValidity(position)) {
								match.registerStone(r, c, s1);
								count++;
								}
								else
								{
									System.out.println("�̹� ���� �������ֽ��ϴ�.");
								}
								if(match.checkWinningCondition(position))
								{
									System.out.println("1��° �÷��̾��� �¸��Դϴ�.");
									System.out.println("���� �÷��̾��� �·�"+p1.getWinningRate());
									break;
									
								}
							}
							else {
								System.out.println("2��° �÷��̾��� �����Դϴ�. ���ϴ� ��ġ�� �����ϼ���");
								int r = sc.nextInt();
								int c = sc.nextInt();
								position = new Position(r,c);
								if(match.checkValidity(position)) {
								match.registerStone(r, c, s2);
								count++;
								}
								else {
									System.out.println("�̹� ���� ������ �ֽ��ϴ�.");
								}
								if(match.checkWinningCondition(position))
								{
									System.out.println("2��° �÷��̾��� �¸��Դϴ�.");
									System.out.println("���� �÷��̾��� �·�"+p1.getWinningRate());
									break;

								}
							}
						}
						else if(start == 3) {
							break;
						}
						else
						{
							System.out.println("1~3�����Ǥ� �����Է�");
						}
					}
				}
				
			}
			else if(choose == 2) {
				match.setPlayType(choose);
				System.out.println("���� ���Ӹ��(1. ����,2.��Ʈ��ũ) :"+match.getPlayType());
				System.out.println("��Ʈ��ũ���� ���� �̱��� �����Դϴ�.");
			}
			else if(choose == 3) {
				break;
			}
			else
			{
				System.out.println("1~3������ �����Է�");
			}
		}
		
	}
	
}
