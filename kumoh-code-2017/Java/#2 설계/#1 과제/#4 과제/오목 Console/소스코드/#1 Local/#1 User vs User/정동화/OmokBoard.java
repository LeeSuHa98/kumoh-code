

public class OmokBoard {
	protected int ROWS = 19; // ����
	protected int COLS = 19; // ����
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
	public OmokBoard(int rows,int cols) {
		StoneType s = StoneType.None;
		this.ROWS = rows;
		this.COLS = cols;
		for(int i=0;i<rows;i++) {
			for(int j=0;j<cols;j++) {
				matrix[i][j] = s;
			}
		}
	}
	public void displayBoard() {
		System.out.println("------ ������ ------");
		for(int i=0;i<ROWS;i++) {
			for(int j=0;j<COLS;j++) {
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
		StoneType s = StoneType.None;
		for(int i=0;i<ROWS;i++) {
			for(int j=0;j<COLS;j++) {
				matrix[i][j] = s;
			}
		}
	}
	public int getRowCount() {
		return ROWS;
	}
	public int getColCount() {
		return COLS;
	}
	
	public void countSameColorStones(Position m, StoneType color,int []stoneNum) {
		for(int i=0;i<8;i++) {
			stoneNum[i] = 0;
		}
		int count=0;
		int colCheck = m.getColumn();
		//����
		for(int i=m.getRow();i<m.getRow()+5;i++) {
			if(i < 0 || i >ROWS) {
				break;
			}
			if(matrix[i][m.getColumn()] == color) {
				stoneNum[count]++;
			}
		}
		count++; // 8������ �迭�߿��� 5���� ������ ��� �¸��ϰԵ�

		//�Ʒ���
		for(int i=m.getRow();i>m.getRow()-5;i--) {
			if(i < 0 || i >ROWS) {
				break;
			}
			if(matrix[i][m.getColumn()] == color) {
				stoneNum[count]++;
			}
		}
		count++;
		//������
		for(int i=m.getColumn();i<m.getColumn()+5;i++) {
			if(i < 0 || i >COLS) {
				break;
			}
			if(matrix[m.getRow()][i] == color) {
				stoneNum[count]++;
			}
		}
		count++;
		//����
		for(int i=m.getColumn();i>m.getColumn()-5;i--) {
			if(i < 0 || i >COLS) {
				break;
			}
			if(matrix[m.getRow()][i] == color) {
				stoneNum[count]++;
			}
		}
		count++;
		//���� �� �밢�� �κ� ��������
		for(int i = m.getRow();i>m.getRow()-5;i--) {
			if(i < 0 || i >ROWS) {
					break;
				}
				if(matrix[i][i] == color) {
					stoneNum[count]++;
				}
			
		}
		count++;
		//������ ��
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
		//���ʾƷ�
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
		//������ �Ʒ�
		for(int i=m.getRow();i<m.getRow()+5;i++) {
				if(i < 0 || i >ROWS) {
					break;
				}
				if(matrix[i][i] == color) {
					stoneNum[count]++;
				}
			
		}
		//���� ��ġ�� �������� 8������ ���� ������ ����Ͽ���
		
	}

}
