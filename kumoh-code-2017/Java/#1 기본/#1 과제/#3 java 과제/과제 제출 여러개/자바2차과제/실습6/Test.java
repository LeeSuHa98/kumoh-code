

import java.util.*;
public class Test {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		Account x, y;
		x = new Account("ȫ�浿", 100);
		
		y =  new Account("ȫ�浿",100);
		System.out.println( x.equals(y) ); 
		
		y = x;
		System.out.println( x.equals(y) ); 
		
		y = (Account) x.clone(); //���� ����� ���� ���۷����� ���������� ��������� �ٸ����۷����� �����ϱ⶧���� ���� ���Ҷ� false���� �����Եȴ�.
		System.out.println( x.equals(y) ); 



		
		
		input.close();
	}

}
