import java.io.IOException;
import java.util.ArrayList;

public class main
{
	public static void main(String[] args)
	{
		ArrayList<String> list = new ArrayList<String>();
		
		FileHandler fh = new FileHandler();
		
		try {
			fh.loadFile("QSortData.txt", list);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		QuickSort q = new QuickSort();
		
		long start = System.currentTimeMillis();
		q.sort(list, 0, list.size() - 1);
		
		long end = System.currentTimeMillis();
		double sortTime = ( end - start ) / 1000.0;
		System.out.println( "실행 시간 : " + sortTime);
		
		double sortTimeStr = sortTime;
		
		String sortName = "QSortData_Java.txt";
		try
		{
			fh.saveFile(sortName + " 결과( " + sortTimeStr + " ).txt", list);
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	} 
}
