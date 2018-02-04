package practice;

public class MyBoard extends OmokBoard {

	Player player;
	MyBoard(int rows,int cols, Player player){
		super(rows,cols);
		this.player = player;
	}
	public void display() {
		for(int i=0;i<ROWS;i++) {
			for(int j=0;j<COLS;j++)
			{
				System.out.print(getStone(i,j)+" ");
			}
			System.out.println();
		}
	}
	public void countSameColorStones(Position m, StoneType color,int []stoneNum) {
		
	}
}
