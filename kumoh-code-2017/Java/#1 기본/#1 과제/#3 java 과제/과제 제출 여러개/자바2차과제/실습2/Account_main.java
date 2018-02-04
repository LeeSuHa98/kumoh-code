
import java.util.*;
public class Account_main {

	public static void main(String[] args) {
		Owner o = new Owner();
		Account a = new Account(100,o);
		
		Scanner input = new Scanner(System.in);
		int accountnum;
		System.out.print("계좌번호입력: ");
		accountnum= input.nextInt();
		a.setAccountnum(accountnum);
		
		
		System.out.println("계: "+a.getAccountnum());
		System.out.println("잔: "+a.getBalance());
		System.out.println("예금주: "+o.getName());
		System.out.println("예금주 주소: "+o.getAddress());
		System.out.println("예금주 전화번호: "+o.getPhonenum());
		
		input.close();
	}

}
