package ����;

public class OmokBoard
{
	// �ٵ����� ��� ���� ����
	private int ROWS;
	private int COLS;
	private StoneType matrix[][];
	// �������� ũ�⸦ 19x19�� ����
	public OmokBoard()
	{
		ROWS = 19;
		COLS = 19;
		matrix = new StoneType[ROWS][COLS];
		
		for(int i = 0; i < ROWS; i++) 
		{
			for(int j = 0; j < COLS; j++) 
			{
				matrix[i][j] = StoneType.None;
			}
		}
	}
	// �������� ũ�⸦ ����
	public OmokBoard(int rows, int cols)
	{
		this.ROWS = rows;
		this.COLS = cols;
		matrix = new StoneType[ROWS][COLS];
		
		for(int i = 0; i < ROWS; i++) 
		{
			for(int j = 0; j < COLS; j++) 
			{
				matrix[i][j] = StoneType.None;
			}
		}
	}
	
	// (x, y) ��ġ�� stone ���� ����
	public void putStone(int x, int y, StoneType stone)
	{
		matrix[x][y] = stone;
	}
	
	// (x, y) ��ġ�� ���� ����, �� (x, y) ��ġ�� ���� StoneType.None���� ����
	public void removeStone(int x, int y)
	{
		matrix[x][y] = StoneType.None;
	}
	// (x, y) ��ġ�� �� ���� ��ȯ
	public StoneType getStone(int x, int y)
	{
		if(x < 0 || y < 0)
		{
			return null;
		}
		else if(x >= ROWS || y >= COLS)
		{
			return null;
		}
		else
		{
			return matrix[x][y];
		}
	}
	// �� �ٵ����� ���� ����. ��, ��� ��ġ�� ���� StoneType.None����
	public void clear()
	{
		for(int i = 0; i < ROWS; i++)
		{
			for(int j = 0; j < COLS; j++)
			{
				matrix[i][j] = StoneType.None;
			}
		}
	}
	
	public int getRowCount() {return ROWS;}	// �ٵ����� �� ���� ��ȯ
	public int getColCount() {return COLS;}	// �ٵ����� �� ���� ��ȯ
	// p ��ġ�� �������� 8������ color ���� ���� �������� ���� ������ �ľ��Ͽ� stoneNum �迭�� ��ȯ. ��, �������� ���� ���Ե��� ���� 
	public void countSameColorStones(Position p, StoneType color, int[] stoneNum)
	{
		// ���� FeedBack : 6�� �̻��� ����?
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow() - i, p.getColumn()) == color)
			{
				stoneNum[0]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow() - i, p.getColumn() + i) == color)
			{
				stoneNum[1]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow(), p.getColumn() + i) == color)
			{
				stoneNum[2]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow() + i, p.getColumn() + i) == color)
			{
				stoneNum[3]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow() + i, p.getColumn()) == color)
			{
				stoneNum[4]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow() + i, p.getColumn() - i) == color)
			{
				stoneNum[5]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow(), p.getColumn() - i) == color)
			{
				stoneNum[6]++;
			}
			else
			{
				break;
			}
		}
		for(int i = 1; i < ROWS; i++)
		{
			if(getStone(p.getRow() - i, p.getColumn() - i) == color)
			{
				stoneNum[7]++;
			}
			else
			{
				break;
			}
		}
	}
	
	public void printBoard() 
	{
		System.out.println("------------------");
		for(int i = 0; i < ROWS; i++) 
		{
			for(int j = 0; j < COLS; j++) 
			{
				if(matrix[i][j] == StoneType.None) 
				{
					//System.out.print(StoneType.None + " ");	// None
					System.out.print("��");	// None

				}
				else if(matrix[i][j] == StoneType.Black)
				{
					//System.out.print(StoneType.Black + " ");	// Black
					System.out.print("��");	// Black
				}
				else
				{
					//System.out.print(StoneType.Black + " ");	// Black
					System.out.print("��");	// White
				}
			}
			System.out.println();
		}
		System.out.println("------------------");
	}
}
