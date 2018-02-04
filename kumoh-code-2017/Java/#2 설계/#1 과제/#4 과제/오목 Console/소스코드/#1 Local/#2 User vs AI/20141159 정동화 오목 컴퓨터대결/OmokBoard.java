package practice;

public class OmokBoard {
	protected int ROWS = 19; // 가로
	protected int COLS = 19; // 세로
	private StoneType [][]matrix = new StoneType[ROWS][COLS];
	public OmokBoard() {
		StoneType s = StoneType.None;
		ROWS = 19;
		COLS = 19;
		for(int i=0;i<ROWS;i++) {
			for(int j=0;j<COLS;j++) {
				matrix[i][j] = s;
			}
		}
	}
	public OmokBoard(int ROWS,int COLS) {
		this.ROWS = ROWS;
		this.COLS = COLS;
		for(int i=0;i<ROWS;i++) {
			for(int j=0;j<COLS;j++) {
				matrix[i][j] = StoneType.None;
			}
		}
	}
	public void displayBoard() {
		System.out.println("------ 오목판 ------");
		for(int i=0;i<getRowCount();i++) {
			for(int j=0;j<getColCount();j++) {
				if(matrix[i][j] == StoneType.None) {
					System.out.print(0+" ");
				}
				else if(matrix[i][j] == StoneType.Black) {
					System.out.print(1+" ");
				}
				else {
					System.out.print(2+" ");
				}
				//System.out.print(matrix[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("------------------");

	}
	public void putStone(int x,int y, StoneType stone) {
		matrix[x][y] = stone;
	}
	public void removeStone(int x,int y) {
		StoneType s = StoneType.None;
		matrix[x][y] = s;
	}
	public StoneType getStone(int x, int y) {
		return matrix[x][y];
	}
	public void clear() {
		for(int i=0;i<getRowCount();i++) {
			for(int j=0;j<getColCount();j++) {
				matrix[i][j] = StoneType.None;
			}
		}
	}
	public int getRowCount() {
		return ROWS;
	}
	public int getColCount() {
		return COLS;
	}
	public void setRow(int row) {
		this.ROWS = row;
	}
	public void setCol(int col) {
		this.COLS = col;
	}
	public void countSameColorStones(Position m, StoneType color,int []stoneNum) {
		for(int i=0;i<8;i++) {
			stoneNum[i] = 0;
		}
		
		int count=0;
		int colCheck = m.getColumn();
		//위쪽
		for(int i=m.getRow();i<m.getRow()+5;i++) {
			if(i < 0 || i >ROWS) {
				break;
			}
			if(matrix[i][m.getColumn()] == color) {
				stoneNum[count]++;
			}
		}
		count++; // 8방향의 배열중에서 5개가 존재할 경우 승리하게됨

		//아래쪽
		for(int i=m.getRow();i>m.getRow()-5;i--) {
			if(i < 0 || i >ROWS) {
				break;
			}
			if(matrix[i][m.getColumn()] == color) {
				stoneNum[count]++;
			}
		}
		count++;
		//오른쪽
		for(int i=m.getColumn();i<m.getColumn()+5;i++) {
			if(i < 0 || i >COLS) {
				break;
			}
			if(matrix[m.getRow()][i] == color) {
				stoneNum[count]++;
			}
		}
		count++;
		//왼쪽
		for(int i=m.getColumn();i>m.getColumn()-5;i--) {
			if(i < 0 || i >COLS) {
				break;
			}
			if(matrix[m.getRow()][i] == color) {
				stoneNum[count]++;
			}
		}
		count++;
		//왼쪽 위 대각선 부분 에러조심
		for(int i = m.getRow();i>m.getRow()-5;i--) {
			if(i < 0 || i >ROWS) {
					break;
				}
				if(matrix[i][i] == color) {
					stoneNum[count]++;
				}
		}
		count++;
		//오른쪽 위
		for(int i=m.getRow();i>m.getRow()-5;i--) {
				if(i < 0 || i >ROWS||colCheck<0||colCheck>COLS) {
					break;
				}
				if(matrix[i][colCheck] == color) {
					stoneNum[count]++;
					colCheck++;
				}
			
		}
		count++;
		//왼쪽아래
		for(int i=m.getRow();i<m.getRow()+5;i++) {
				if(i < 0 || i >ROWS||colCheck<0||colCheck>COLS) {
					break;
				}
				if(matrix[i][colCheck] == color) {
					colCheck--;
					stoneNum[count]++;
				}
		}
		count++;
		//오른쪽 아래
		for(int i=m.getRow();i<m.getRow()+5;i++) {
				if(i < 0 || i >ROWS) {
					break;
				}
				if(matrix[i][i] == color) {
					stoneNum[count]++;
				}
			
		}
		//현재 위치를 기준으로 8방향의 돌의 갯수를 계산하였음
		
	}

}
