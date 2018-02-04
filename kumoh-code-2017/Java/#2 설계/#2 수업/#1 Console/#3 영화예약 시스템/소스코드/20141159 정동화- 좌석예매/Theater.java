
public class Theater  {

	private String [][]seats;
	private int rows;
	private int cols;
	
	public int getRows() {
		return rows;
	}
	
	public int getCols() {
		return cols;
	}
	
	public String getSeats(int row,int col) {
		return seats[row][col];
	}
	
	public void setSeats(int row,int col,String name) {
		this.rows = row;
		this.cols = col;
		seats[row][col] = name;
	}
	
	public Theater(int rows,int cols){
		this.cols = cols;
		this.rows = rows;
		seats = new String[rows][cols];
		for(int i=0;i<rows;i++) {
			for(int j=0;j<cols;j++) {
				seats[i][j] = "0";
			}
		}
	}
	public void reserve(int row,int col) throws MyException {
		if(getSeats(row,col) == "0") {
			setSeats(row,col,"1");
			System.out.println("예약완료");
		}
		else {
			throw new MyException("1");
		}
	}
	public void show_seats(int row, int col) {
		int count = 0;
		
		System.out.println("=<좌석 배치도(값이 1인경우 예약된 자리입니다.)>=");
		
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(getSeats(i,j) == "1") {
					count++;
				}
				System.out.print(getSeats(i,j)+" ");
			}
			System.out.println();
		}	
		int sum = row*col - count;
		System.out.println("빈 좌석수 : "+sum+" || 예약된 좌석수: "+count);
		
	}
	public void reserve_cancel(int row,int col) throws MyException {
		if(getSeats(row,col)=="0") {
			throw new MyException("2");
		}
		else {
			setSeats(row,col,"0");
		}
	}
	
}
