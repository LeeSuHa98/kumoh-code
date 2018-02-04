

public class Position {

	
	private int row;
	private int column;
	
	Position(int r,int c){
		this.row = r;
		this.column = c;
	}
	public int getRow() {
		return row;
	}
	public int getColumn() {
		return column;
	}
	public void setRow(int r) {
		this.row = r;
	}
	public void setColumn(int c) {
		this.column = c;
	}
}
