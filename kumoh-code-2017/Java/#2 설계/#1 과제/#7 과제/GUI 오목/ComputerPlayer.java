package ����;

public class ComputerPlayer extends Player
{
	public ComputerPlayer(int id, String name, int order, int winningRate)
	{
		super(id, name, order, winningRate);
	}
	// ��ǻ�Ͱ� ���� ���� ��ġ�� �ڵ����� ����Ͽ� ����. �� ��ġ�� evaluatePosition �޼ҵ带 ����Ͽ� �� �߿� ���� ���� ���� ��ġ�� ����
	public Position play(OmokBoard board)
	{
		int weight = 0;
		int maxX = 0;
		int maxY = 0;

		for(int x = 0; x < board.getRowCount(); x++)
		{
			for(int y = 0; y < board.getColCount(); y++)
			{
				if(evaluatePosition(board, x, y) + measureDistance(board, x, y) > weight)
				{	// ����ġ ��� + �Ÿ���� > ����ġ
					weight = evaluatePosition(board, x, y) + measureDistance(board, x, y);
					
					maxX = x;
					maxY = y;
				}
			} 
		}
		Position p = new Position(maxX, maxY);
		
		return p;
	}
	
	private int evaluatePosition(OmokBoard board, int x, int y)
	{
		if(board.getStone(x, y) != StoneType.None)
		{
			return 0;
		}
		
		int []stoneNum = new int[8];
		int []opStoneNum = new int[8];
		boolean []isBlockage = new boolean[8];		//�ڽ��� ������ �������� �����ִ��� �ȸ����ִ��� Ȯ��
		boolean []opIsBlockage = new boolean[8];	//����� ������ �������� �����ִ��� �ȸ����ִ��� Ȯ��
		StoneType color = StoneType.None;
		StoneType opColor = StoneType.None;
		Position p = new Position(x, y);
		if(order == 1)
		{
			color = StoneType.Black;
			opColor = StoneType.White;
		}
		else if(order == 2)
		{
			color = StoneType.White;
			opColor = StoneType.Black;
		}

		countSameColorStones(board, p, color, stoneNum , isBlockage);	//�ȹ������� ���ӵ� ������ ������ stoneNum�� ��� �������� �����ִ����� isBlockage�� ��´�.
		countSameColorStones(board, p, opColor, opStoneNum , opIsBlockage);
		int weight = checkWeight(stoneNum, isBlockage, opStoneNum, opIsBlockage);	//����ġ�� ����ؼ� ��ȯ
		
		return weight;
	}
	
	private int getIndexMaxSameColor(int[] stoneNum)	//������ ���ӵ� ������ ���� ���帹�� �ε����� ã�Ƽ� ��ȯ
	{
		int MaxSame = 0;
		int index = 0;
		for(int i = 0 ; i < 4; i++)
		{
			if(stoneNum[i] + stoneNum[i + 4] > MaxSame)
			{
				MaxSame = stoneNum[i] + stoneNum[i + 4];
				index = i;
			}
		}
		return index;
	}
	private int checkWeight(int[] stoneNum , boolean[] isBlockage, int[] opStoneNum, boolean[] opIsBlockage)
	{			//����ġ�� ����ؼ� ��ȯ
		int index = getIndexMaxSameColor(stoneNum);			//	�ڽ��� �� ����� ���� ���ӵ� ���� ������ ���� ū ���� ������ �ε���
		int opIndex = getIndexMaxSameColor(opStoneNum);		//	������ �� ����� ���� ���ӵ� ���� ������ ���� ū ���� ������ �ε���
		int count = stoneNum[index] + stoneNum[index + 4] + 1;	//	�� ���� ��ġ�� �ڽ��� ������ ���� �� ���ӵ� ����
		int opCount = opStoneNum[opIndex] + opStoneNum[opIndex + 4] + 1;	//	�翷�� ��ġ�� ��밡 ������ ���� �� ���ӵ� ����
		
		int weight = 0;
		//	(x, y)�� ��ġ �� ���
		if(count == 5)
		{
			weight = 100;	// 1) ���� ���� ������ ��� 5�� �ϼ� (100)
		} 
		else if(opCount == 5)
		{
			weight = 90;	// 2) ������ ���� ������ ��쿡 5�� �ϼ� (90)
		}
		else if(count == 4)
		{
			weight = 80;	// 3) ���� 4�� (�� ��)������ ��� (80) 
		}
		else if(opCount == 4)
		{
			weight = 75;	// 4) ���� 4�� (�� ��)������ ��� (75) 
		}
		else if(count == 4 && (isBlockage[index] == true||isBlockage[index+4] == true))
		{
			weight = 70;	// 5) �� �� 4�� (����)������ ��� (70)
		}
		else if(opCount == 4 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
		{
			weight = 65;	// 6) ���� 4�� (����)������ ���(65) 
		}
		else if(count == 3)
		{
			weight = 60;	// 7) �� �� 3�� (�� ��)������ ��� (60) 
		}
		else if(opCount == 3)
		{
			weight = 55;	// 8) ���� 3�� (�� ��)������ ��� (55) 
		}
		else if(count == 3 && (isBlockage[index] == true||isBlockage[index+4] == true))
		{
			weight = 50;	// 9) �� �� 3�� (����)������ ��� (50)
		}
		else if(opCount == 3 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
		{
			weight = 45;	// 10) ���� 3�� (����)������ ��� (45) 
		}
		else if(count == 2)
		{
			weight = 40;	// 11) �� �� 2�� (�� ��)������ ��� (40) 
		}
		else if(opCount == 2)
		{
			weight = 35;	// 12) ���� 2�� (�� ��)������ ��� (35) 
		}
		else if(count == 2 && (isBlockage[index] == true||isBlockage[index+4] == true))
		{
			weight = 30;	// 13) �� �� 2�� (����)������ ��� (30) 
		}
		else if(opCount == 2 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
		{
			weight = 25;	// 14) ���� 2�� (����)������ ��� (25)
		}
		else if(count == 1)
		{
			weight = 20;	// 15) �� �� 1�� (�� ��)������ ��� (20) 
		}
		else if(opCount == 1)
		{
			weight = 15;	// 16) ���� 1�� (�� ��)������ ��� (15)
		}
		else if(count == 1 && (isBlockage[index] == true||isBlockage[index+4] == true))
		{
			weight = 10;	// 17) �� �� 1�� (����)������ ��� (10) 
		}
		else if(opCount == 1 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
		{
			weight = 5;		// 18) ���� 1�� (����)������ ��� (5)
		}
		return weight;
	}
	public int measureDistance(OmokBoard board, int x, int y)
	{		//�Ÿ��� ����ؼ� ����ġ�� ���Ͽ� ��ȯ
		double centerDistance = board.getRowCount() / 2;
		double rowd =  Math.abs(x - centerDistance);		//�Ÿ��� ����ϱ� ������ ���밪
		double cold = Math.abs(y - centerDistance);
		double distance = 0;
		if(rowd < cold)
		{
			distance = cold;
		}
		else
		{
			distance = rowd;
		}
		// �߾ӿ������� ���� ��ġ������ �Ÿ��� �������� ���
		if(distance >= centerDistance * 4/5)
		{
			return 1;	// 5�����̸� 1�� �ο�
		}
		else if(distance >= centerDistance * 3/5)
		{
			return 2;	// 4�����̸� 2�� �ο�
		}
		else if(distance >= centerDistance * 2/5)
		{
			return 3;	// 3�����̸� 3�� �ο�
		}
		else if(distance >= centerDistance * 1/5)
		{
			return 4;	// 2�����̸� 4�� �ο�
		}
		else 
		{
			return 5;	// 1�����̸� 5�� �ο�
		}
	}
	public void countSameColorStones(OmokBoard board, Position p, StoneType color, int[] stoneNum, boolean[] isBlockage)
	{
		//�ȹ������� ���ӵ� ������ ������ stoneNum�� ��� �������� �����ִ����� isBlockage�� ��´�.
		StoneType oppenentColor = StoneType.None;	//���� �� ����
		if(color == StoneType.White)
		{
			oppenentColor = StoneType.Black;
		}
		else
		{
			oppenentColor = StoneType.White;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow() - i, p.getColumn()) == color)
			{
				stoneNum[0]++;
			}
			else if(board.getStone(p.getRow() - i, p.getColumn()) == oppenentColor)
			{
				isBlockage[0] = true;			// ���� �� ����� ������ ��������
				break;
			}				
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow() - i, p.getColumn() + i) == color)
			{
				stoneNum[1]++;
			}
			else if(board.getStone(p.getRow() - i, p.getColumn() + i) == oppenentColor)
			{
				isBlockage[1] = true;
				break;
			}
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow(), p.getColumn() + i) == color)
			{
				stoneNum[2]++;
			}
			else if(board.getStone(p.getRow(), p.getColumn() + i) == oppenentColor)
			{
				isBlockage[2] = true;
				break;
			}
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow() + i, p.getColumn() + i) == color)
			{
				stoneNum[3]++;
			}
			else if(board.getStone(p.getRow() + i, p.getColumn() + i) == oppenentColor)
			{
				isBlockage[3] = true;
				break;
			}
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow() + i, p.getColumn()) == color)
			{
				stoneNum[4]++;
			}
			else if(board.getStone(p.getRow() + i, p.getColumn()) == oppenentColor)
			{
				isBlockage[4] = true;
				break;
			}
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow() + i, p.getColumn() - i) == color)
			{
				stoneNum[5]++;
			}
			else if(board.getStone(p.getRow() + i, p.getColumn() - i) == oppenentColor)
			{
				isBlockage[5] = true;
				break;
			}
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow(), p.getColumn() - i) == color)
			{
				stoneNum[6]++;
			}
			else if(board.getStone(p.getRow() , p.getColumn() - i) == oppenentColor)
			{
				isBlockage[6] = true;
				break;
			}
			else break;
		}
		for(int i = 1; i < board.getRowCount(); i++)
		{
			if(board.getStone(p.getRow() - i, p.getColumn() - i) == color)
			{
				stoneNum[7]++;
			}
			else if(board.getStone(p.getRow() - i, p.getColumn() - i) == oppenentColor)
			{
				isBlockage[7] = true;
				break;
			}
			else break;
		}
	}
}
