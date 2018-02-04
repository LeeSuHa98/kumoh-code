package 오목;

public class Position
{
	// 움직일 위치의 row, column 값
	private int row;
	private int column;
	
	public Position(int row, int column)
	{
		this.row = row;
		this.column = column;
	}
	
	public int getRow() {return row;}	// row값 반환
	public int getColumn() {return column;}	// column값 반환
}
