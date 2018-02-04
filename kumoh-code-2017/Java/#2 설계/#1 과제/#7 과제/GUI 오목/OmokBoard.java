package 오목;

public class OmokBoard
{
	// 바둑판의 행과 열의 개수
	private int ROWS;
	private int COLS;
	private StoneType matrix[][];
	// 오목판의 크기를 19x19로 설정
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
	// 오목판의 크기를 설정
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
	
	// (x, y) 위치에 stone 값을 저장
	public void putStone(int x, int y, StoneType stone)
	{
		matrix[x][y] = stone;
	}
	
	// (x, y) 위치의 돌을 제거, 즉 (x, y) 위치의 값을 StoneType.None으로 변경
	public void removeStone(int x, int y)
	{
		matrix[x][y] = StoneType.None;
	}
	// (x, y) 위치의 돌 값을 반환
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
	// 현 바둑판의 돌을 제거. 즉, 모든 위치의 값을 StoneType.None으로
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
	
	public int getRowCount() {return ROWS;}	// 바둑판의 행 개수 반환
	public int getColCount() {return COLS;}	// 바둑판의 열 개수 반환
	// p 위치를 기준으로 8방향의 color 값을 갖는 연속적인 돌의 개수를 파악하여 stoneNum 배열로 반환. 단, 기준점의 돌은 포함되지 않음 
	public void countSameColorStones(Position p, StoneType color, int[] stoneNum)
	{
		// 과제 FeedBack : 6개 이상일 때는?
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
					System.out.print("□");	// None

				}
				else if(matrix[i][j] == StoneType.Black)
				{
					//System.out.print(StoneType.Black + " ");	// Black
					System.out.print("●");	// Black
				}
				else
				{
					//System.out.print(StoneType.Black + " ");	// Black
					System.out.print("○");	// White
				}
			}
			System.out.println();
		}
		System.out.println("------------------");
	}
}
