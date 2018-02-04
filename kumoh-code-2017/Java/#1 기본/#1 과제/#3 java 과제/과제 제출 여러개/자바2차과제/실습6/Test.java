

import java.util.*;
public class Test {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		Account x, y;
		x = new Account("홍길동", 100);
		
		y =  new Account("홍길동",100);
		System.out.println( x.equals(y) ); 
		
		y = x;
		System.out.println( x.equals(y) ); 
		
		y = (Account) x.clone(); //얕은 복사는 같은 래퍼런스를 참조하지만 깊은복사는 다른래퍼런스를 참조하기때문에 둘을 비교할때 false값이 나오게된다.
		System.out.println( x.equals(y) ); 



		
		
		input.close();
	}

}
