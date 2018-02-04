package practice;


import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Theater  {

	private int [][]seats;
	private int rows = 5;
	private int cols = 5;
	
	public int getRows() {
		return rows;
	}
	
	public int getCols() {
		return cols;
	}
	
	public int getSeats(int row,int col) {
		return seats[row][col];
	}
	
	public void setSeats(int row,int col,int name) {
		seats[row][col] = name;
	}
	
	public Theater(){
		seats = new int[rows][cols];
		for(int i=0;i<rows;i++) {
			for(int j=0;j<cols;j++) {
				seats[i][j] = 0;
			}
		}
	}
	public void reserve(int row,int col) throws MyException {
		if(getSeats(row,col) == 0) {
			setSeats(row,col,1);
			System.out.println("����Ϸ�");
		}
		else {
			throw new MyException("1");
		}
	}
	public void show_seats() {
		int count = 0;
		
		System.out.println("=<�¼� ��ġ��(���� 1�ΰ�� ����� �ڸ��Դϴ�.)>=");
		
		for(int i=0;i<rows;i++) {
			for(int j=0;j<cols;j++) {
				if(getSeats(i,j) == 1) {
					count++;
				}
				System.out.print(getSeats(i,j)+" ");
			}
			System.out.println();
		}	
		int sum = rows*cols - count;
		System.out.println("�� �¼��� : "+sum+" || ����� �¼���: "+count);
		
	}
	public void reserve_cancel(int row,int col) throws MyException {
		if(getSeats(row,col)==0) {
			throw new MyException("2");
		}
		else {
			setSeats(row,col,0);
		}
	}
	public void load(String f_name) throws IOException
	{
		try {
			FileInputStream fout = new FileInputStream(f_name);
			InputStreamReader in = new InputStreamReader(fout);
			char c;
			for(int i=0;i<rows;i++) {
				for(int j=0;j<cols;j++) {
					c = (char) in.read();
					seats[i][j] = Integer.parseInt(Character.toString(c));
				}
			}
			System.out.println("�ҷ����⸦ �Ϸ��߽��ϴ�");
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("����");
		}
	}
	
	public void save(String f_name) throws IOException
	{
		
		try {
			FileOutputStream fos = new FileOutputStream(f_name);
			OutputStreamWriter out = new OutputStreamWriter(fos);
			for(int i=0;i<cols;i++) {
				for(int j =0;j<rows;j++) {
					out.write(Integer.toString(seats[i][j]));
				}
			}
			out.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}
}
